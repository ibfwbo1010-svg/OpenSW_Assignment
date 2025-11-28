#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main () {
    pid_t my_pid = getpid();
    printf("%d\n",my_pid);
    return 0;
}