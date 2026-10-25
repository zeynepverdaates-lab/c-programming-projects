# include <stdio.h>

int main(void){

    int a,b,c;

    printf("enter three integers : ");
    scanf("%d%d%d",&a,&b,&c);

    if (a < b && a < c && b < c){
        printf(" %d < %d < %d",a,b,c);
    }

    else if (a < b && a < c && b > c){
        printf(" %d < %d < %d",a,c,b);
    }

    else if (a > b && a > c && b < c){
        printf(" %d < %d < %d",b,c,a);
    }

    else if (a > b && a > c && b > c){
        printf(" %d < %d < %d",c,b,a);
    }
    
    else if (a > b && a < c && b < c){
        printf(" %d < %d < %d",b,a,c);
    }

    else  {
        printf(" %d < %d < %d",c,a,b);
    }
    
}