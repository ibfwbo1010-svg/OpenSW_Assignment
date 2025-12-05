#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int mysystem(const char* command) {
    pid_t pid = fork();
    if (pid == 0) {
        execl("/bin/sh", "sh", "-c", command, (char *)0);
        exit(1);
    }
    int status;
    waitpid(pid, &status, 0);
    return 0;
}
int main(void) {
    // mysystem("ls -l | wc -l");
    // mysystem("find . -name '*.c'");
    mysystem("ls -l | wc -l");
     mysystem("find . -name '*.c'");
    printf("Good Bye\n");
    return 0;
}
