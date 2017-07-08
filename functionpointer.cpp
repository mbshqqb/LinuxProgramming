//
// Created by mbshqqb on 16-12-2.
//
#include <stdio.h>

int sum(int x,int y){
    return x+y;
}
int mul(int x,int y){
    return x*y;
}
int cal(int x,int y,int (*f)(int, int)){
    return f(x,y);
}
int main(){
printf("%d",cal(1,2,sum));
    printf("%d",cal(1,2,mul));
    printf("%d",cal(1,2,sum));
}
