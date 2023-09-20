#include<iostream>
using namespace std;
int main()
{
    int A[3];
    int n, k, l, c, d, p, nl, np;
    int Min;
    cin>>n>>k>>l>>c>>d>>p>>nl>>np;
    A[0]=c*d;
    A[1]=(k*l)/nl;
    A[2]=p/np;
    Min=A[0];
    for(int i=0; i<3; i++)
    {
        if(A[i]<Min)
        {
            Min=A[i];
        }
    }
    cout<<Min/n;
}
