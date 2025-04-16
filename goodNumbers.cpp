#include <bits/stdc++.h>
using namespace std;
int countGoodNumbers(long long n)
{
    if(n==1) return 5;
    double l = (double)n / 2;

    long long o = floor(l);
    long long e = ceil(l);
    cout<<(pow(5,e)*pow(4,o))%(1e9+7);
    return pow(5,e)*pow(4,o);
}
int main()

{
    
    cout << countGoodNumbers(50) << endl;
    
}