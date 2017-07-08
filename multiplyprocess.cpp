//
// Created by mbshqqb on 16-12-7.
//
#include <stdio.h>
#include <unistd.h>
#include <cstdlib>

int main(){
    int rv;
    if((rv=fork())==-1){
        printf("cannot fork\n");
        exit(1);
    }else if(rv==0){
        printf("I am child\n");
    }else{
        wait(NULL);
        printf("I am parent\n");
    }
}

