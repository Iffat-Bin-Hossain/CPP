//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution{

    // Function to find the trapped water between the blocks.
    public:
    long long leftMax(int arr[],int i){
        long long max=arr[i];
        for(int x=0;x<i;x++){
            if(arr[x]>max){
                max=arr[x];
            }
        }
        return max;
    }
    long long rightMax(int arr[],int i,int n){
        long long max=arr[i];
        for(int x=i;x<n;x++){
            if(arr[x]>max){
                max=arr[x];
            }
        }
        return max;
    }
    long long trappingWater(int arr[], int n){
        // code here
        long long *firstToLast,*lastToFirst;
        firstToLast=new long long[n];
        lastToFirst=new long long[n];
        firstToLast[0]=arr[0];
        lastToFirst[n-1]=arr[n-1];
        for(int i=1;i<n;i++)
        {
            firstToLast[i]=leftMax(arr,i);
            lastToFirst[n-i-1]=rightMax(arr,n-i-1,n);
        }
        long long trappedWater=0;
        for(int i=1;i<n-1;i++){
            trappedWater+=min(firstToLast[i],lastToFirst[i])-arr[i];
        }
        return trappedWater;
        
    }
};

//{ Driver Code Starts.

int main(){
    
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        
        int a[n];
        
        //adding elements to the array
        for(int i =0;i<n;i++){
            cin >> a[i];            
        }
        Solution obj;
        //calling trappingWater() function
        cout << obj.trappingWater(a, n) << endl;
        
    }
    
    return 0;
}
// } Driver Code Ends