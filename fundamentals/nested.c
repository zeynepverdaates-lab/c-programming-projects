# include <stdio.h>

int main(void){
    int i,j;

    for(i=2; i<=5; i++){
        for(j=2; j<=5; j++){
            printf("%2d  ",i*j);
        }
        printf("\n");
    }
}
