//
// Created by mbshqqb on 16-12-9.
//
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
    close(1);//关闭当前进程的1号标准输入,不会改变父进程的
    int fd=open("bar.txt",O_WRONLY|O_CREAT,0644);
    printf("%d\n",fd);
    execlp("who","who",NULL);
    return 0;
}
