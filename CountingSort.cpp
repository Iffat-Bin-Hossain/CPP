#include <bits/stdc++.h>
using namespace std;
int maximum(int n,int A[]){
    int Max=INT_MIN;
    for(int i=0;i<n;i++){
        Max=max(Max,A[i]);
    }
    return Max;
}
void countingSort(int n, int A[])
{
    int max=maximum(n,A);
    int *count;
    count=new int[max+1];
    for(int i=0;i<=max;i++){
        count[i]=0;
    }
    for(int i=0;i<n;i++){
        count[A[i]]++;
    }
    int i=0;
    for(int j=0;j<=max;j++){
        if(count[j]!=0){
            A[i]=j;
            i++;
        }
    }
}
void printArray(int n,int A[]){
    for (int i = 0; i < n; i++)
    {
        cout<< A[i]<<" ";
    }
    cout<<endl;
}
int main()
{
    int n;
    cin >> n;
    int A[n];
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }
    printArray(n,A);
    countingSort(n, A);
    printArray(n,A);
}