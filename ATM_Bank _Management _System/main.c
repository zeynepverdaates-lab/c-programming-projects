#include <stdio.h>
#include "prototype.h"
#include "functions.h"

int main(){

    int control=0,a=0,choice=0,account_no,no=0;
    float amount=0.0;
    client new;
    
    printf("\nWELCOME\n");

    do{
        printf("\nPlease enter your password to perform a transaction on your account(-1 to exit): ");
        scanf("%d",&control);

        if(control==-1){
            return 0;
        } 

        FILE* fptr=fopen("clients.txt","r");

        if(fptr==NULL){
            printf("The file could not be opened!");
        }
        else{
            rewind(fptr);
        }

        while(!feof(fptr)){
            fscanf(fptr,"%s %s %d %d %f",new.name,new.surname,&new.no,&new.password,&new.cash);
            if(control==new.password){
                account_no =new.no;
                printf("\nYou have successfully logged into your account.\n");
                a=1;
                break;
            }
        }
        fclose(fptr);

        if(a==0){
        printf("\nCould not log into your account! Please try again.\n");
        }

        
    }while(a==0);
    
    menu();

    while(choice!=5){
        printf("\nChoose the transaction you want to perform: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter the amount of deposit: ");
                scanf("%f",&amount);
                deposit(amount,account_no);
                //printf("Your balance has been updated to %.2f.\n",deposit(amount,account_no));
                break;
            case 2:
                printf("Enter the amount of withdrawal: ");
                scanf("%f",&amount);
                withdrawal(amount,account_no);
                break;
            case 3:
                balance_inquiry(account_no);
                break;
            case 4:
                printf("Enter the account number for the transfer/EFT: ");
                scanf("%d",&no);
                printf("Enter the amount for the transfer/EFT: ");
                scanf("%f",&amount);
                transfer(no,amount,account_no);
                break;
            case 5:
                printf("You have logged out");
                return 0;
                break;
            default :
                printf("Please enter a number between 1 and 5!");
        }
    }
}