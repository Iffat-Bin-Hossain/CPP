#include<iostream>
using namespace std;
template<class T>void BubbleSort(T A[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(A[i]>A[j])
            {
                T Temp=A[i];
                A[i]=A[j];
                A[j]=Temp;

            }
        }
    }
}
template<class T>void PrintArray(T A[],int n)
{
    for(int i=0; i<n; i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int A1[]= {3,1,2,5,4,8,6};
    int n1=sizeof(A1)/sizeof(A1[0]);
    int A2[]= {'q','t','l','n','r'};
    int n2=sizeof(A2)/sizeof(A2[0]);
    double A3[]= {3.45,2.51,1.22,5.67,4.38,8.45,6.35};
    double n3=sizeof(A3)/sizeof(A3[0]);
    PrintArray(A1,n1);
    PrintArray(A2,n2);
    PrintArray(A3,n3);
    BubbleSort(A1,n1);
    BubbleSort(A2,n2);
    BubbleSort(A3,n3);
    PrintArray(A1,n1);
    PrintArray(A2,n2);
    PrintArray(A3,n3);
}
