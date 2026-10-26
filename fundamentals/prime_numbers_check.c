# include <stdio.h>

int main(void){
    int i,x,a=0;
    printf("enter a number:");
    scanf("%d",&x);

    for(i=2 ; i<x; i++){
        if(x % i == 0){
            printf("this is not a prime number");
            a = 1;
            break;
    }
    }
    if(a != 1){
        printf("this is a prime number");
    }
}
