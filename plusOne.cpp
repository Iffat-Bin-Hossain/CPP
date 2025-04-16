#include <bits/stdc++.h>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    long long int l = digits.size();
   long long int num = 0;
    for (long long int i = 0; i < l; i++)
    {
        num = (num * 10) + digits[i];
    }
    num = num + 1;
    long long int div = num;
    long long int rem = num;
    digits = {};
    while (div != 0)
    {
        rem = div % 10;
        div = div / 10;
        digits.push_back(rem);
    }
    reverse(digits.begin(), digits.end());
    return digits;
}
int main()
{
    vector<int> digits = {9};
    plusOne(digits);
    for(int i = 0; i < digits.size(); i++){
        cout<<digits[i]<<" ";
    }
}