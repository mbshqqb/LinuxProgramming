#include <cstdio>

//
// Created by mbshqqb on 16-11-30.
//
#include <termios.h>
#include <unistd.h>
int main(){
    char name[512];
    char pass[512];
    scanf("%s",name);

    struct termios setup,backup;
    tcgetattr(0,&setup);
    backup=setup;
    //关闭回显
    setup.c_lflag &=~ECHO;
    tcsetattr(0,TCSANOW,&setup);
    //读入密码
    scanf("%s",pass);
    //继续打开回显
    tcsetattr(0,TCSANOW,&backup);
}
