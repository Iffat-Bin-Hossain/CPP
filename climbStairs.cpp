#include <iostream>
using namespace std;
int climbStairs(int n)
{
    int climbStairs[n];
    climbStairs[0] = 1;
    climbStairs[1] = 2;
    for (int i = 2; i < n; i++)
    {
        climbStairs[i] = climbStairs[i - 1] + climbStairs[i - 2];
    }
    return climbStairs[n - 1];
}
int main()
{
    int n;
    cin >> n;
    cout << climbStairs(n) << endl;
    return 0;
}