#include <stdio.h>
float us_fonksiyonu(float a, int b);


int main(void){
    
    float base=0, result;
    int exponential=0;

    printf("enter base and exponential:");
    scanf("%f%d",&base,&exponential);

    result = us_fonksiyonu(base,exponential);
    printf("result is %.2f",result);


}

float us_fonksiyonu(float a, int b){
   
    float result = 1;

    if(b < 0){
        for(int i = 1; i <= -b; i++){
            result *= 1/a;
        }
    }
    else if(b == 0){
        result = 1;
    }
    else{
        for(int i = 1; i <= b; i++){
            result *= a;
        }
    }
return result;
}