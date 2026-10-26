# include <stdio.h>

int fibonacci(int);  

int main(void){
    int x;

    printf("enter a number:");
    scanf("%d",&x);

    printf("%d",fibonacci(x));
}

int fibonacci(int n){

    int i=1,a=1,b=1,total;

    while(i<= n+1){
        total = a + b;
        a = b;
        b = total;
        i++;
     
    }
return total;
}

/*FOR RECURSİVE FONCTION
# include <stdio.h>  

int fib(int);

int main(void){
    int x;
    printf("enter a number:");
    scanf("%d",&x);

    printf("%d",fib(x));
}

int fib(int n){

    if(n==1){
        return 0;
    
    }
    else if(n==2){
        return 1;
        
    }
    else
        return fib(n-1)+fib(n-2);
}*/
     


