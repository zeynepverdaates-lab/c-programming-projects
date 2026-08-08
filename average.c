# include <stdio.h>

int main(void){

    float grade,total =0.0;
    float average;
    int i=1;
    

    do{
        printf("enter %dth exam grade  : ",i);
        scanf("%f",&grade);

        if(grade == 0){
            break;
        }
        else if(grade < 0){
            printf("enter a positive");
            continue;
        }

        else{
            total += grade;
            i++;
            
        }
        

    }while(grade != 0);

    average = total / (i-1);
    printf("%f is the average",average);
}