# include <stdio.h>

int main(void){

    int number,a,b,c,d;

    printf("enter a 4-digit number : ");
    scanf("%d",&number);

    a = number / 1000;
    b = (number % 1000) / 100;
    c = (number % 100) / 10;
    d = number % 10;

    printf(" %d\t%d\t%d\t%d",a,b,c,d);
}