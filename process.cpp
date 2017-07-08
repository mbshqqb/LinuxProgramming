//
// Created by mbshqqb on 16-12-7.
//


#include <stdio.h>
#include <unistd.h>

int main(){
    int rv;
    rv=fork();
    printf("I am %d,rv=%d\n",getpid(),rv);
    return 0;
}
void test(){
    printf("father is %d\n",getpid());
    fork();
    fork();
    fork();
    printf("I am %d\n",getpid());
}