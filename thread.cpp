#include <pthread.h>
#include <stdio.h>
//
// Created by mbshqqb on 16-12-16.
//
void* print(void*argv){//返回值为void*
    printf("******");
}

int main(){
    pthread_t t1;//线程句柄
    pthread_create(&t1,NULL,print,NULL);//最后一个参数表示传递的参数
}
