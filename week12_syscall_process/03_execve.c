#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[], char *envp[])
{
    if (argc < 2) {
        printf("Usage: ./03_execve <program path> [OPTION]...\n");
        exit(1);
    }

    pid_t pid = fork();
    int status;

    if (pid == 0) {
        // child
        char *program = argv[1];
        char **args = &argv[1];  // argv[1]부터 execve 인자로 전달

        if (execve(program, args, envp) == -1) {
            perror("execve failed");
            exit(1);
        }
    }

    // parent
    waitpid(pid, &status, 0);

    if (WIFEXITED(status)) {
        printf("Child exited with code: %d\n", WEXITSTATUS(status));
    }

    return 0;
}
