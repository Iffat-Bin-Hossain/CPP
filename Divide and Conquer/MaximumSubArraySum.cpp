#include<bits/stdc++.h>
#include<vector>
using namespace std;
int crossSubArray(int Arr[],int left,int mid,int right){
int Sum=0;
int leftSum=INT_MIN;
for(int i=left;i<=mid;i++){
    Sum+=Arr[i];
    if(Sum>leftSum){
        leftSum=Sum;    
    }
}
Sum=0;
int rightSum=INT_MIN;
for(int i=mid;i<=right;i++){
    Sum+=Arr[i];
    if(Sum>rightSum){
        rightSum=Sum;    
    }
}
return max(max(leftSum,rightSum),leftSum+rightSum-Arr[mid]);
}
int maximumSubArraySum(int Arr[],int left,int right){
    if(left>right){
        return INT8_MIN;
    }
    if(left==right){
        return Arr[left];
    }
    else{
    int mid=(left+right)/2;
    return max(max(maximumSubArraySum(Arr,left,mid-1),maximumSubArraySum(Arr,mid+1,right)),crossSubArray(Arr,left,mid,right)) ;

    }
}
int main()
{
    int A[10]={1 ,3 ,-2, -1,7,6,2,-5,10,-8};
    int maxSum=maximumSubArraySum(A,0,9);
    cout<<maxSum<<endl;
}