#include <iostream>
using namespace std;
void Merge(int Arr[], int left, int mid,int right)
{
    int llen = mid-left + 1;
    int rlen = right - mid;
    int leftArr[llen];
    int rightArr[rlen];
    for (int i = 0; i < llen; i++)
        leftArr[i] = Arr[left + i];
    for (int j = 0; j < rlen; j++)
        rightArr[j] = Arr[mid + 1 + j];
    int i=0,j=0,k=left;
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
}
void MergeSort(int Arr[], int left, int right)
{
    if (left >= right){
       return;
    }
    int mid = (left+right)/2;
    MergeSort(Arr, left, mid);
    MergeSort(Arr, mid+1,right);
    Merge(Arr,left,mid,right);
}
void printArray(int Arr[], int size)
{
    for (int i = 0; i < size; i++){
      cout << Arr[i] << " ";
    }
    cout<<endl;

}
int main()
{
    int arr[] = { 12, 11, 13, 5, 6, 7 };
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Before Sorting:"<<endl;
    printArray(arr,size);
    MergeSort(arr, 0,size-1);
    cout << "After Sorting:"<<endl;
    printArray(arr,size);
    return 0;
}
