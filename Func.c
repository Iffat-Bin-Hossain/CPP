#include <stdio.h>
void isPrime(int n)
{
    if (n == 0 || n == 1){
        printf("%d is not prime\n", n);
        return;
    }
    else{
        int count=0;
        for(int i=1;i<=n;i++){
            if(n%i == 0){
                count++;
            }
        }
        if(count==2){
            printf("%d is prime\n", n);
        }
        else{
            printf("%d is not prime\n", n);
        }
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    isPrime(n);
}
