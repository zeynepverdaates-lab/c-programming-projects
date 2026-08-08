#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu()
{

    printf(" ________________________________________\n");
    printf("|          PHONEBOOK APPLICATION         |\n");
    printf("|                                        |\n");
    printf("| 1. Add phone                           |\n");
    printf("| 2. List the phones                     |\n");
    printf("| 3. Search                              |\n");
    printf("| 4. Delete the phone                    |\n");
    printf("| 5. Log out                             |\n");
    printf("|                                        |\n");
    printf("|________________________________________|\n");
}

int phoneadd()
{

    record newrecord;
    FILE *fptr;
    fptr = fopen("phonebook.txt", "a");
    if (fptr == NULL)
    {
        return -1;
    }
    printf("\n\n");
    printf("enter the name(max 20 character):");
    scanf("%s", newrecord.name);
    printf("enter the surname(max 20 character):");
    scanf("%s", newrecord.surname);
    printf("enter the phone number(max 20 character):");
    scanf("%s", newrecord.phone);

    fprintf(fptr, "\n\n%s %s %s", newrecord.name, newrecord.surname, newrecord.phone);
    fclose(fptr);
    return 0;
}

int phonelist()
{

    record currentRecord;
    FILE *fptr;
    fptr = fopen("phonebook.txt", "r");
    if (fptr == NULL)
    {
        return -1;
    }
    printf("\n\nNAME\t\t\tSURNAME\t\t\tPHONE\n");
    printf("-----\t\t\t-------\t\t\t-------\n\n");

    while (fscanf(fptr, "%s%s%s", currentRecord.name, currentRecord.surname, currentRecord.phone) == 3)
    {
        printf("%s\t\t\t%s\t\t\t%s\n", currentRecord.name, currentRecord.surname, currentRecord.phone);
    }

    fclose(fptr);
    return 0;
}

int phonesearch(char *ptrsearch)
{

    record currentrecord;
    int i = 0;
    FILE *fptr;
    fptr = fopen("phone.txt", "r");
    if (fptr == NULL)
    {
        return -1;
    }

    while (!feof(fptr))
    {
        fscanf(fptr, "%s%s%s", currentrecord.name, currentrecord.surname, currentrecord.phone);
        if (!strcmp(ptrsearch, currentrecord.name))
        {
            printf("%s\t\t\t", currentrecord.name);
            printf("%s\t\t\t", currentrecord.surname);
            printf("%s\n", currentrecord.phone);
            i++;
        }
    }

    fclose(fptr);
    return i;
}

int phoneDelete(char *ptrName, char *ptrSurname)
{

    record currentRecord;
    char rehber[100];

    FILE *fptr1 = fopen("phonebook.txt", "r");
    FILE *fptr2 = fopen("temporary.txt", "w");

    if (fptr1 == NULL || fptr2 == NULL)
    {
        return -1;
    }

    while (fscanf(fptr1, "%s %s %s", currentRecord.name, currentRecord.surname, currentRecord.phone) == 3)
    {
        if (strcmp(currentRecord.name, ptrName) == 0 && strcmp(currentRecord.surname, ptrSurname) == 0)
        {
            printf("%s %s is deleted from phonebook.\n", currentRecord.name, currentRecord.surname);
        }
        else
        {
            fprintf(fptr2, "%s %s %s\n", currentRecord.name, currentRecord.surname, currentRecord.phone);
        }
    }

    fclose(fptr1);
    fclose(fptr2);
    remove("phonebook.txt");
    rename("temporary.txt", "phonebook.txt");

    return 0;
}