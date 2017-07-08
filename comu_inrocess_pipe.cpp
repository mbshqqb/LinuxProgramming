//
// Created by mbshqqb on 16-12-9.
//

//
// Created by mbshqqb on 16-12-9.
//

#include <unistd.h>
#include <stdio.h>
int main(){

    int pipefd[2];//0 write,1 read
    int rv_fd;
    char buff[1024];
    pipe(pipefd);


    write(pipefd[1],"hello world",11);//写入1
    int n=read(pipefd[0],buff,sizeof(buff));//从0读
    printf("%.*s\n",n,buff);

    rv_fd=fork();
    if(0==rv_fd){
        close(pipefd[1]);
        close(0);
        dup(pipefd[0]);//复制到最小的可用文件描述符，此时为刚关闭的0
        execlp("wc","wc","-l",NULL);
        close(pipefd[0]);
    }else{
        close(pipefd[0]);
        close(1);
        dup(pipefd[1]);//复制到最小的可用文件描述符，此时为刚关闭的1
        execlp("ls","ls","/bin",NULL);
        close(pipefd[1]);
    }
}