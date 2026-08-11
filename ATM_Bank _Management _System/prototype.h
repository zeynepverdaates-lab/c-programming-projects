typedef struct {
    char name[30];
    char surname[30];
    int no;
    int password;
    float cash;
}client;

void menu();
float deposit(float,int);
int withdrawal(float,int);
float balance_inquiry(int);
int transfer(int,float,int);
