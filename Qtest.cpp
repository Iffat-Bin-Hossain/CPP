//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends
class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high){
            return;
        }
        int pivotIndex=partition(arr,low,high);
        quickSort(arr,low,pivotIndex-1);
        quickSort(arr,pivotIndex+1,high);
    }
    
    public:
    int partition (int arr[], int low, int high)
    {
        int pivot=arr[high];
        int pivotindex=-1;
        for(int i=0;i<high;i++){
            if(arr[i]<pivot){
                pivotindex++; 
                int T=arr[i];
                arr[i]=arr[pivotindex];
                arr[pivotindex]=T;
                //swap(arr[i],arr[pivotindex]);
            }
        swap(arr[high],arr[pivotindex+1]);
        return pivotindex+1;
        }
       // Your code here
    }
};

//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends