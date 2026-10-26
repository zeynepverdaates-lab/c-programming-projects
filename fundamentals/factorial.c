# include <stdio.h>

int main(void){
    int i,number;
    int factorial=1;
    
    printf("enter a number: ");
    scanf("%d",&number);

    for(i=1; i <= number; i++){
        factorial *= i;
    }
    printf("factorial is %d",factorial);
}