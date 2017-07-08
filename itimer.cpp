#include <sys/time.h>
#include <bits/signum.h>
#include <signal.h>

//
// Created by mbshqqb on 16-12-2.
//
#include <stdio.h>
#include <cstdlib>
#include <unistd.h>

void f(int n){
printf("Alarm!\n");
}
int main(){
    struct  itimerval ival;
    signal(SIGALRM,f);
    ival.it_interval.tv_sec=1;
    ival.it_interval.tv_usec=0;//间隔

    ival.it_value.tv_sec=0;//起始时间
    ival.it_value.tv_usec=1;

    setitimer(ITIMER_REAL,&ival,NULL);
    for (int i = 0; i < 10; ++i) {
        printf("%d\n",i);
        pause();//暂停
    }
}