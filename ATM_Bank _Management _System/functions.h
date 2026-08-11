#include <stdio.h>

void menu()
{

    printf(" ________________________________________\n");
    printf("|               ISLEMLER                 |\n");
    printf("|                                        |\n");
    printf("| 1. DEPOSIT                             |\n");
    printf("| 2. WITHDRAWAL                          |\n");
    printf("| 3. BALANCE INQUIRY                     |\n");
    printf("| 4. TRANSFER/EFT                        |\n");
    printf("| 5. EXIT                                |\n");
    printf("|                                        |\n");
    printf("|________________________________________|\n");
}

float deposit(float amount,int account_no){
    float new_balance=0.0;
    client record;

    FILE* fptr1=fopen("clients.txt","r");
    FILE* fptr2=fopen("new.txt","w");
    
    if(fptr1==NULL){
        printf("the file could not be opened");
        return -1;
    }
    if(fptr2==NULL){
        printf("the file could not be opened");
        return -1;
    }
    else{
        rewind(fptr1);
        rewind(fptr2);
    }

    while(fscanf(fptr1,"%s %s %d %d %f",record.name,record.surname,&record.no,&record.password,&record.cash)==5){
        
        if(record.no==account_no){
            record.cash += amount;
            new_balance=record.cash;
        }
        fprintf(fptr2,"%s\t%s\t%d\t%d\t%.2f\n",record.name,record.surname,record.no,record.password,record.cash);
        
    }
    printf("Your balance has been updated to %.2f",new_balance);
    fclose(fptr1);
    fclose(fptr2);
    remove("clients.txt");
    rename("new.txt","clients.txt");
}

int withdrawal(float amount,int account_no){
    float new_balance=0.0;
    client record;

    FILE* fptr1=fopen("clients.txt","r");
    FILE* fptr2=fopen("new.txt","w");
    
    if(fptr1==NULL){
        printf("the file could not be opened");
        return -1;
    }
    if(fptr2==NULL){
        printf("the file could not be opened");
        return -1;
    }
    else{
        rewind(fptr1);
        rewind(fptr2);
    }

    while(fscanf(fptr1,"%s %s %d %d %f",record.name,record.surname,&record.no,&record.password,&record.cash)==5){
        if(record.no==account_no){
            record.cash -= amount;
            new_balance=record.cash;
        }     
        fprintf(fptr2,"%s\t%s\t%d\t%d\t%.2f\n",record.name,record.surname,record.no,record.password,record.cash);
    }
    printf("Your balance has been updated to %.2f.\n",new_balance);
    fclose(fptr1);
    fclose(fptr2);
    remove("clients.txt");
    rename("new.txt","clients.txt");  
}

float balance_inquiry(int account_no){
    
    client record;
    float b=0.0;
    FILE* fptr=fopen("clients.txt","r");

    
    if(fptr==NULL){
        printf("the file could not be opened");
        return -1;
    }
    else{
        rewind(fptr);
    }

    while(fscanf(fptr,"%s %s %d %d %f",record.name,record.surname,&record.no,&record.password,&record.cash)==5){
        if(record.no==account_no){
            b=record.cash;
        }
    }
    printf("Your balance is %.2f",b);

    fclose(fptr);

}

int transfer(int no, float amount,int account_no){
   
    client record;
    int a=0;
    FILE* fptr1=fopen("clients.txt","r");
    FILE* fptr2=fopen("new.txt","w");
    if(fptr1==NULL){
        printf("the file could not be opened");
        return -1;
    }
    if(fptr2==NULL){
        printf("the file could not be opened");
        return -1;
    }
    else{
        rewind(fptr1);
        rewind(fptr2);
    }

    while(fscanf(fptr1,"%s %s %d %d %f",record.name,record.surname,&record.no,&record.password,&record.cash)==5){
        if(record.no==no){
            record.cash += amount;
            fprintf(fptr2,"%s\t%s\t%d\t%d\t%.2f\n",record.name,record.surname,record.no,record.password,record.cash);
            a=1;
            printf("The transfer transaction has been completed.");
        }
        else if(record.no==account_no){
            record.cash -= amount;
            fprintf(fptr2,"%s\t%s\t%d\t%d\t%.2f\n",record.name,record.surname,record.no,record.password,record.cash);
        }
        else{
            fprintf(fptr2,"%s\t%s\t%d\t%d\t%.2f\n",record.name,record.surname,record.no,record.password,record.cash); 
        }
    }
    if(a=0){
        printf("The EFT transaction has been completed.");
    }
    fclose(fptr1);
    fclose(fptr2);
    remove("clients.txt");
    rename("new.txt","clients.txt");

}
 