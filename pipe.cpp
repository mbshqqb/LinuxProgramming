//
// Created by mbshqqb on 16-12-9.
//

#include <unistd.h>
#include <stdio.h>
int main(){

    int pipefd[2];//0 read,1 write
    char buff[1024];
    pipe(pipefd);
    write(pipefd[1],"hello world",11);
    int n=read(pipefd[0],buff,sizeof(buff));
    printf("%.*s\n",n,buff);
}