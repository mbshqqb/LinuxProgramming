//
// Created by mbshqqb on 16-12-7.
//

#include <unistd.h>
#include <stdio.h>
#include <cstdlib>

int main(){
    int rv;
    if((rv=fork())==-1){
        printf("cannot fork\n");
        exit(1);
    }else if(rv==0){
        char*argv[]={"ls","/",NULL};
        printf("want to exe!\n");
        execv("ls",argv);//给ls一个子进程
        printf("Finished!\n");//此句不会执行
        printf("I am child\n");
    }else{
        printf("I am parent\n");
    }
}
void test(){
    char*argv[]={"ls","/",NULL};
    printf("want to exe!\n");
    execv("ls",argv);//将ls的代码段拷贝到自己的代码段，ls进场执行结束后该进程也会结束，后面的代码不会执行
    printf("Finished!\n");//此句不会执行
}