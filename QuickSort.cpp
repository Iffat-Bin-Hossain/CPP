#include<iostream>
using namespace std;
//first element as pivot

// int Partition(int Arr[],int left,int right){
//     int x=right;
//     int pivot=Arr[left];
//     for(int i=right;i>left;i--){
//         if(Arr[i]>pivot){
//             swap(Arr[x--],Arr[i]);
//         }
//     }
//     swap(Arr[x],Arr[left]);
//     return x;
// }

//Last element as pivot
int Partition(int Arr[],int left,int right){
    int x=left;
    int pivot=Arr[right];
    for(int i=left;i<right;i++){
        if(Arr[i]<pivot){
            swap(Arr[x++],Arr[i]);
        }
    }
    swap(Arr[x],Arr[right]);
    return x;
}
void QuickSort(int Arr[],int left,int right)
{
    if(left>=right)
    {
        return;
    }
    int pivotIndex=Partition(Arr,left,right);
    QuickSort(Arr,left,pivotIndex-1);
    QuickSort(Arr,pivotIndex+1,right);
}
int main()
{
int A[10]={9,5,2,6,8,3,1,4,10,7};
cout<<"Before Quick Sort:"<<endl;
for(int i=0;i<10;i++){
    cout<<A[i]<<" ";
}
cout<<endl;
QuickSort(A,0,9);
cout<<"After Quick Sort:"<<endl;
for(int i=0;i<10;i++){
    cout<<A[i]<<" ";
}
cout<<endl;


}
