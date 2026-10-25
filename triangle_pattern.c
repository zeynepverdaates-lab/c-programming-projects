# include <stdio.h>
int main(void){

    int i,j;

    for(i=1; i<=5; i++){

        for(j=1; j<=i; j++){
            printf(" * ");
        }
    printf("\n");
    }

    /*for(i=5; i>0; i--){  //inverted triangle
        for(j=1; j<=i; j++){
            printf(" * ");
        }
    printf("\n");
    }*/

    /*# include <stdio.h>  //right-aligned triangle
int main(void){
    int i,j;
    
    for(i=5; i>0; i--){

        for(int k=0; k<=5-i; k++){
            printf(" ");
        }
        for(j=1; j<=i; j++){
            printf("*");
        }
    printf("\n");
    }
}*/
}