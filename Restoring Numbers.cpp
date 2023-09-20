#include<iostream>
using namespace std;
int main()
{
    int A[4],Max,i;
    for(i=0; i<4; i++)
    {
        cin>>A[i];
    }
    Max=A[0];
    for(i=1; i<4; i++)
    {
        if(A[i]>Max)
        {
            Max=A[i];
        }
    }
    for(i=0; i<4; i++)
    {
        if(A[i]!=Max)
        {
            cout<<Max-A[i]<<" ";
        }
    }

}
