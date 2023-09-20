#include <iostream>
using namespace std;
int Merge(int Arr[], int left, int mid,int right)
{
    int inversion=0;
    int llen = mid-left + 1;
    int rlen = right - mid;
    int leftArr[llen];
    int rightArr[rlen];
    for (int i = 0; i < llen; i++)
        leftArr[i] = Arr[left + i];
    for (int j = 0; j < rlen; j++)
        rightArr[j] = Arr[mid + 1 + j];
    int i,j;
    int k=left;
    i=0;
    j=0;
    while (i <llen && j <rlen)
    {
        if (leftArr[i]<=rightArr[j])
        {
            Arr[k]=leftArr[i];
            k++;
            i++;
        }
        else
        {
            Arr[k]=rightArr[j];
            inversion+=llen-i;
            j++;
            k++;
        }
    }
    while (i<llen)
    {
        Arr[k]=leftArr[i];
        k++;
        i++;
    }
    while (j<rlen)
    {
        Arr[k]=rightArr[j];
        k++;
        j++;
    }
    return inversion;
}
int MergeSort(int Arr[], int left, int right)
{
    int inversion=0;
    if (left < right)
    {
        int mid = (left+right)/2;
        inversion+=MergeSort(Arr, left, mid);
        inversion+=MergeSort(Arr, mid+1,right);
        inversion+=Merge(Arr,left,mid,right);
    }
    return inversion;

}
void printInversionPair(int Arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for(int j=i+1; j<size; j++)
        {
            if(Arr[i]>Arr[j])
            {
                cout<<"("<<Arr[i]<<","<<Arr[j]<<"),";
            }
        }
    }
    cout<<endl;

}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    cout<<"Inversion Pair:"<<endl;
    printInversionPair(arr,n);
    cout<<"Total Inversion:"<<MergeSort(arr, 0,n-1)<<endl;

    return 0;
}
