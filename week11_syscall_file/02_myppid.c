#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main () {
    pid_t my_pid = getpid();
    pid_t my_ppid = getppid();

    printf("pid = %d\n",(int)my_pid);
    printf("ppid = %d\n",(int)my_ppid);
    return 0;
}