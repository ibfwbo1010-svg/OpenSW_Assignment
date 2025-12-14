#include<stdio.h>
 #include<unistd.h> 
 #include<sys/types.h> 
 #include<signal.h> 
 #include<sys/wait.h> 
 void SIGINT_handler(int signo){ 
    pid_t pid = fork(); 
    char *argv[] = { "ls",NULL}; 
    if(pid == 0){ 
        execve("/usr/bin/ls",argv,NULL); 
        exit(0); 
    } 
    else{ 
        wait(NULL); } 
    } 

 void SIGQUIT_handler(int signo){ 
        pid_t pid = fork(); 
        char *argv[] = {"date",NULL}; 
        if(pid == 0){ 
            execve("/usr/bin/date",argv,NULL); 
            exit(0); 
        } 
        else{ 
            wait(NULL);
         } 
 } 
void sigalrm_handler(int signo){ 
            pid_t pid = fork(); 
            char *argv[] = {"whoami",NULL}; 
            if((pid ==0)){ 
                execve("/usr/bin/whoami",argv,NULL); 
                exit(0); 
            } 
            else{ 
                wait(NULL);
             } 
             alarm(3); 
 } 

int main () { 
    struct sigaction sa_int; 
    struct sigaction sa_quit; 
    struct sigaction sa_alrm; 
    sa_int.sa_handler = SIGINT_handler; 
    sigemptyset(&sa_int.sa_mask); 
    sa_int.sa_flags = 0; 
    sa_quit.sa_handler = SIGQUIT_handler; 
    sigemptyset(&sa_quit.sa_mask); 
    sa_quit.sa_flags = 0; 
    sa_alrm.sa_handler = sigalrm_handler; 
    sigemptyset(&sa_alrm.sa_mask); 
    sa_alrm.sa_flags = 0; 
    sigaction(SIGINT, &sa_int, NULL); 
    sigaction(SIGQUIT, &sa_quit, NULL); 
    sigaction(SIGALRM, &sa_alrm, NULL); 
    pid_t pid; 
    alarm(3); 
    while(1){ 
        pid = getpid();
         printf("%d\n",pid);
          sleep(1); 
    } 
return 0; 
}