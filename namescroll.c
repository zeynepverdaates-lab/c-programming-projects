# include <stdio.h>
# include <stdlib.h>
# include <math.h>

void namescroll(char* , int);

int main(void){

    char name[8]= {'S','O','F','T','W','A','R','E'};
    int size = sizeof(name)/sizeof(name[0]);

    namescroll(name,size);
    
    
}

void namescroll(char* matrix, int n){
    int i=0,j=0;

    for(i=0; i<n+1; i++){
        for(j=i; j<n; j++ ){
            printf("%c", *(matrix+j));
        }
        for(j=0; j<i; j++){
            printf("%c",*(matrix+j));
        }
        printf("\n");
    }

}
