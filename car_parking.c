# include <stdio.h>

float calculatepayment(float);
float hours[100],payment[100];

int main(void){
    int n;
    float total;

    printf("Enter number of cars:");
    scanf("%d", &n);

    for(int i=0; i<n; i++) {
        printf("Enter parking time:");
        scanf("%f",&hours[i]);

    }

    for(int i=0; i<n; i++) {
        payment[i]= calculatepayment(hours[i]);
        total += calculatepayment(hours[i]); 
    }

    
    printf("-----------------------------------------------\n");
    printf("car\tparking time\tpayment\n");
    printf("-----------------------------------------------\n");
    for(int i=0;i<n; i++ ){
        printf("%d\t",i+1);
        printf("%.2f\t\t",hours[i]);
        printf("%.2f\n",payment[i]);
    }
    
    printf("-----------------------------------------------\n");
    printf("TOTAL REVENUE\t %d\n",total);  
    
}


float calculatepayment(float x){
    float total;
    if(x <= 3) total = 2;
    else if(x<24) total = 2 + (x*0.5);
    else total = 10;

    return total;
}