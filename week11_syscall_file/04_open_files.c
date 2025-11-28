#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include <errno.h>   
#include <string.h>

int main (int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [file1 name] ...\n", argv[0]);
        exit(0);
    }
    int num_files = argc - 1;
    int* fd_list = (int*) malloc(sizeof(int)*num_files);
    for (int i = 0; i < num_files; i++) {
        fd_list[i] = open(argv[i+1], O_RDONLY);
        if (fd_list[i] == -1) {
            printf("Error opening file %s: %s\n", argv[i+1], strerror(errno));
        } else {
            printf("Opened file %s with file descriptor %d\n", argv[i+1], fd_list[i]);
        }
    }   
    for(int i=0; i<num_files; i++) {
        if (fd_list[i] != -1) {
            close(fd_list[i]);
        }
    }
    free(fd_list);
    
    return 0;
}