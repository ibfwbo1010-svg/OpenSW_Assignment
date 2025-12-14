#include<stdio.h>
#include<unistd.h> 
#include<sys/types.h> 
#include<signal.h> 
#include<sys/wait.h> 
int main(){

sigset_t mask;
sigemptyset(&mask);
sigaddset(&mask, SIGINT);
sigprocmask(SIG_BLOCK, &mask, NULL);

sleep(5);

sigset_t pending;

sigpending(&pending);

if (sigismember(&pending, SIGINT)) {
    printf("SIGINT is pending\n");
} else {
    printf("SIGINT is not pending\n");
}


    return 0;
}