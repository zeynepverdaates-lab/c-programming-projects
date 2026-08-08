typedef struct{
    char name[20];
    char surname[20];
    char phone[11];

}record;

void menu();
int phoneadd();
int phonelist();
int phonesearch(char*);
int phoneDelete(char*, char*);