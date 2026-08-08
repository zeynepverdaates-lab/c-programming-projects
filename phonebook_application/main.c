#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "prototype.h"
#include "functions.h"

int main(void)
{
    int choice = 0;
    char searchname[20], deleteName[40], ptrName[20], ptrSurname[20];
    int searchresult = 0, result = 0;

    menu();

    while (choice != 5)
    {
        printf("\n\nenter your choice:");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (phoneadd() == 0)
            {
                printf("\nphone number be added");
            }
            else
            {
                printf("\nphone number could not be added!");
            }
            break;
        case 2:
            if (phonelist() == 0)
            {
                printf("\nThe phone number has been listed.");
            }
            else
            {
                printf("\nThe phone number could not be listed.!");
            }
            break;
        case 3:
            printf("enter the name(max 20 character):");
            scanf("%s", searchname);
            searchresult = phonesearch(searchname);
            if (searchresult == 0)
            {
                printf("\nThe requested record was not found.!\n");
            }
            else
            {
                printf("\nA total of %d records were found.\n", searchresult);
            }
            break;

        case 4:
            printf("\nEnter the first name and surname to be deleted:");
            scanf("%s %s", ptrName, ptrSurname);
            phoneDelete(ptrName, ptrSurname);
            break;

        case 5:
            printf("\nYou have logged out.\n");
            return 0;
            break;
        default:
            printf("Please make a selection between 1 and 5!\n");
        }
    }
}