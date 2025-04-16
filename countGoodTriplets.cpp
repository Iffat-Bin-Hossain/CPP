#include <bits/stdc++.h>
using namespace std;
int countGoodTriplets(vector<int> &arr, int a, int b, int c)
{
    int count=0;
    
    vector<vector<int>> y;
    int l = arr.size();
    for (int i = 0; i < l - 2; i++)
    {
        for (int j = i+1; j < l - 1; j++)
        {
            for (int k = j+1; k < l; k++)
            {
                vector<int> x;
                if(abs(arr[i] - arr[j])<=a && abs(arr[j] - arr[k])<=b && abs(arr[i] - arr[k])<=c){
                    // x.push_back(arr[i]);
                    // x.push_back(arr[j]);
                    // x.push_back(arr[k]);
                    // y.push_back(x);
                    count++;
                }
            }
        }
    }
    // for(int i=0;i<y.size();i++){
    //     for(int p:y[i]){
    //         cout<<p<<",";
    //     }
    //     cout<<endl;
    // }
    return count;
}
int main()
{

    vector<int> v = {3, 0, 1, 1, 9, 7};
    int a = 7;
    int b = 2;
    int c = 3;
    cout << countGoodTriplets(v, a, b, c);
}