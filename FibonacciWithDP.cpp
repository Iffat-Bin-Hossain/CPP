#include<iostream>
#include<vector>
using namespace std;
int Fibonacci(int n,int Table[])
{
    if(n==0)
    {
        return 0;
    }
    if (n==1)
    {
        Table[1]=1;
        return 1;
    }
    if(Table[n]!=-1)
    {
        return Table[n];
    }
    else
    {
        Table[n]=Fibonacci(n-1,Table)+Fibonacci(n-2,Table);
        return Table[n];
    }
}
int main()
{
    int n;
    cin>>n;
    int  Table[n+1];
    for(int i=0; i<=n; i++)
    {
        Table[i]=-1;
    }
    cout<<Fibonacci(n,Table);

}

