//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution
{
public:
    long long int decToBin(int d)
    {
        int b = 0;
        int T = d;
        int p = 0;
        while (T != 0)
        {
            int r = T % 2;
            b += r * pow(10, p++);
            T /= 2;
        }
        return b;
    }
    int setSetBit(int x, int y, int l, int r)
    {
        // code here
        stringstream bxStream, byStream;
        bxStream << decToBin(x);
        byStream << decToBin(y);
        string bx = bxStream.str();
        string by = byStream.str();
        for (int i = l - 1; i < by.size(); i++)
        {
            if (bx[i] == 0 && by[i] == 1)
            {
                bx[i] = 1;
            }
        }
        int ret = 0;
        for (int i = 0; i < bx.size(); i++)
        {
            ret += bx[i] * pow(2, i);
        }
        return ret;
    }
};

//{ Driver Code Starts.
int main()
{
<<<<<<< HEAD
    for(int i = 0; i <100;i++)
{
   cout<<"Hello World"<<endl; 
}
=======
    int t;
    cin >> t;
    while (t--)
    {
        int x, y, l, r;
        cin >> x >> y >> l >> r;

        Solution ob;
        cout << ob.setSetBit(x, y, l, r) << "\n";
    }
    return 0;
>>>>>>> 2d9ae1b333355b75265b613239deb0d9cab22702
}
// } Driver Code Ends