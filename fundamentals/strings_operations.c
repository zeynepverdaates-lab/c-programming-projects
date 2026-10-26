# include <stdio.h>

void sort();
void writearray();
void reversearray();

int i,numbers[7];

int main(void){

    printf("enter the numbers one by one:");
    for(i=0; i<7; i++){
        scanf("%d",&numbers[i]);      
    }
    printf("array is ");
    writearray();
    printf("\nsort array is ");
    sort();
    writearray();
    printf("\nreverse array is ");
    reversearray();
}

void sort(void){

    int value,j;
    for(i=0; i<7; i++){
        for(j=i+1; j<7; j++){
            if(numbers[j] < numbers[i]){
                value = numbers[j];
                numbers[j]=numbers[i];
                numbers[i]=value;
            }
        }
    }

}

void writearray(void){
    for(i=0; i<7; i++){
        printf("%d ",numbers[i]);
    }
}

void reversearray(void){
    for(i=6; i>=0; i--){
        printf("%d ",numbers[i]);
    }    
}


