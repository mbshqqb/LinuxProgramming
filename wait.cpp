//
// Created by mbshqqb on 16-12-7.
//
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <cstdlib>

int main(){
    int rv;
    if((rv=fork())==-1){
        printf("cannot fork\n");
        exit(1);
    }else if(rv==0){
        printf("want to exe!\n");
        sleep(10000);
        printf("I am child\n");
        exit(10);//退出子进程
    }else{
        printf("I am parent\n");
        pid_t child_pid;
        int status;
        child_pid=wait(&status);
        printf("waiting child:%d, child exit: %d, child killed by signal:%d\n",child_pid,status>>8,status&0x7F);
       //sleep(1000);
    }

}