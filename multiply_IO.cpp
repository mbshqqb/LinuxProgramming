//
// Created by mbshqqb on 16-12-16.
//

#include <fcntl.h>

int main(){
    int fdtty;
    int fdmice;
    if((fdtty=open("/dev/pts/2",O_RDONLY))==-1){

    }

    if((fdtty=open("/dev/etc/mice",O_RDONLY))==-1){

    }
}