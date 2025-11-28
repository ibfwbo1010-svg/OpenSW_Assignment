#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]) {
    int i;
    if (argc < 3) {
        fprintf(stderr, "Usage: %s [source] [dest1] [dest2] ...\n", argv[0]);
        return 1;
    }
    char *src_name = argv[1];
    int src_fd = open(src_name, O_RDONLY);
    if (src_fd == -1) {
        perror(src_name);
        return 1;
    }
    int dest_count = argc - 2;          
    int dest_fds[dest_count];
    for (i = 0; i < dest_count; i++) {
        char *dest_name = argv[i + 2];
        int fd = open(dest_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror(dest_name);
            dest_fds[i] = -1;  
        } else {
            dest_fds[i] = fd;
        }
    }
    char buf[32];
    ssize_t n;
    int ret = 0;
    while (1) {
        n = read(src_fd, buf, sizeof(buf));
        if (n == 0) {
            break;
        } else if (n == -1) {
            perror("read");
            ret = 1;
            break;
        }
        if (write(STDOUT_FILENO, buf, n) == -1) {
            perror("write stdout");
            ret = 1;
            break;
        }
        for (i = 0; i < dest_count; i++) {
            if (dest_fds[i] == -1) continue;  
            if (write(dest_fds[i], buf, n) == -1) {
                perror("write dest");
                ret = 1;
            }
        }
    }
    close(src_fd);
    for (i = 0; i < dest_count; i++) {
        if (dest_fds[i] != -1) {
            close(dest_fds[i]);
        }
    }
    return ret;
}
