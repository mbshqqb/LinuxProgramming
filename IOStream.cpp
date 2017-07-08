//
// Created by mbshqqb on 16-12-7.
//

#include <fcntl.h>
#include <cstdio>
#include <unistd.h>

int main(){
    int fd=open("笔记",O_WRONLY|O_CREAT);
    fprintf(stderr,"fd is %d\n",fd);//将本来输出到文件的内容重定向到stderr来输出
    close(fd);

    //若没有flush则haha不会输出
    close(stdout);
    printf("haha");
    //fflush(stdout);

}