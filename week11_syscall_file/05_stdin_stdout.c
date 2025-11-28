#include <unistd.h>
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


#define BUF_SIZE 128

int main(int argc, char *argv[]) {

    if (argc != 1) {
        printf("Usage: %s\n", argv[0]);
        exit(1);
    }

    char *readStr = (char *)malloc(sizeof(char) * BUF_SIZE);
    if (readStr == NULL) {
        perror("malloc");
        exit(1);
    }

    ssize_t read_result;   

    while (1) {
       
        read_result = read(STDIN_FILENO, readStr, BUF_SIZE);

        if (read_result == 0) {
           
            break;
        } else if (read_result < 0) {
        
            perror("read");
            free(readStr);
            return 1;
        }

       
        if (write(STDOUT_FILENO, readStr, read_result) < 0) {
            perror("write");
            free(readStr);
            return 1;
        }
    }

    free(readStr);
    return 0;
}
