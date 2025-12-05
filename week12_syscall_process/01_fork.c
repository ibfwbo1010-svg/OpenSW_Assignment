#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {  
    pid_t child_pid;
    int status;

    child_pid = fork();

    // ---------------- Child Process ----------------
    if (child_pid == 0) {
        printf("Child process PID: %lu\n", (unsigned long)getpid());
        printf("Child process PPID: %lu\n", (unsigned long)getppid());
        exit(7);
    }

    // ---------------- Parent Process ----------------
    waitpid(child_pid, &status, 0);

    printf("Child exited with status: %d\n", WEXITSTATUS(status));
    printf("Parent process PID: %lu\n", (unsigned long)getpid());
    printf("Parent process PPID: %lu\n", (unsigned long)getppid());

    return 0;
}
