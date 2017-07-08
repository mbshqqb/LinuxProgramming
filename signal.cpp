//
// Created by mbshqqb on 16-11-30.
//

#include <csignal>
#include <stdio.h>
void f(int i){
    printf("haha!\n");
}
int main(){
    signal(9,f);//，全名是IGNORE忽略2号信号，注意9号信号不可忽略
    while(true){
        printf("只能怪\n");
    }
}