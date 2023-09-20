//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//class implemented
class Item
{
public:
    int value;
    int weight;
};


class Solution
{
public:
    //Function to get the maximum total value in the knapsack.
    void Merge(Item Arr[], int left, int mid,int right)
    {
        int llen = mid-left + 1;
        int rlen = right - mid;
        Item leftArr[llen];
        Item rightArr[rlen];
        for (int i = 0; i < llen; i++)
            leftArr[i] = Arr[left + i];
        for (int j = 0; j < rlen; j++)
            rightArr[j] = Arr[mid + 1 + j];
        int i,j;
        int k= left;
        i=0;
        j=0;
        while (i <llen && j <rlen)
        {
            if ((float)leftArr[i].value/leftArr[i].weight>=(float)rightArr[j].value/rightArr[j].weight)
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
    void MergeSort(Item Arr[], int left, int right)
    {
        if (left >= right)
        {
            return;
        }
        int mid = (left+right)/2;
        MergeSort(Arr, left, mid);
        MergeSort(Arr, mid+1,right);
        Merge(Arr,left,mid,right);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        MergeSort(arr,0,n-1);
        for(int i=0; i<n; i++)
        {
            cout<<arr[i].value<<" "<<arr[i].weight<<endl;
        }
        float remainingWeight=(float)W;
        float Profit=0.00;
        for(int i=0; i<n; i++)
        {
            if(arr[i].weight<=remainingWeight)
            {
                Profit+=arr[i].value;
                remainingWeight-=arr[i].weight;
            }
            else
            {
                if(remainingWeight!=0)
                {
                    float ratio=remainingWeight/=(float)arr[i].weight;
                    Profit+=ratio*arr[i].value;
                    break;
                }


            }
        }
        return Profit;
    }

};


//{ Driver Code Starts.
int main()
{
    int t;
    //taking testcases
    cin>>t;
    cout<<setprecision(2)<<fixed;
    while(t--)
    {
        //size of array and weight
        int n, W;
        cin>>n>>W;

        Item arr[n];
        //value and weight of each item
        for(int i=0; i<n; i++)
        {
            cin>>arr[i].value>>arr[i].weight;
        }

        //function call
        Solution ob;
        cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
    }
    return 0;
}
// } Driver Code Ends
