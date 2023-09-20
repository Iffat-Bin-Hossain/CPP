#include<bits/stdc++.h>
using namespace std;
int CrossSum(int A[],int mid)
{
    return A[mid-1]+A[mid]+A[mid+1];
}
int MaximumTripleSum(int A[],int left,int right)
{
    if(right<left+2){
        return INT_MIN;
    }
    if(right==left+2)
    {
        int Sum=0;
        for(int i=left;i<=right;i++){
            Sum+=A[i];
        }
        return Sum;
    }
    int mid=(left+right)/2;
    int lSum=MaximumTripleSum(A,left,mid);
    int rSum=MaximumTripleSum(A,mid+1,right);
    return max(max(lSum,rSum),CrossSum(A,mid));

}
int main()
{
    int A[10]= {1,2,3,45,-1,9,10,12,-2,6};
    cout<<"Maximum triplet Sum:"<<MaximumTripleSum(A,0,9);

}
