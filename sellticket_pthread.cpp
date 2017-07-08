#include <pthread.h>
#include <stdio.h>
#include <unistd.h>

//
// Created by mbshqqb on 16-12-16.
//
pthread_mutex_t lock=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t flag=PTHREAD_COND_INITIALIZER;
int ticket_num=10;
(void*) print(void*argv){//返回值为void*
    char *station_name;
    station_name=(char*)argv;
    while (1){
        //枷锁
        pthread_mutex_lock(&mutex);
        if(ticket_num>0){
            printf("%s is selliing %d\n",station_name,ticket_num);
            ticket_num--;
            sleep(1);
        }else{
            break;
        }
        //解锁
        pthread_mutex_unlock(&mutex);
        sleep(1);//防止解完锁后立即加锁
    }
}

int main(){
    pthread_t t1;//线程句柄
    pthread_t t2;//线程句柄


    pthread_create(&t1,NULL,print,"沈阳南");//最后一个参数表示传递的参数
    pthread_create(&t2,NULL,print,"沈阳北");//最后一个参数表示传递的参数
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
}
