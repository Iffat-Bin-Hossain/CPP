//Given an integer array nums, return the most frequent even element.

//If there is a tie, return the smallest one. If there is no such element, return -1.
#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    return (a.second > b.second)&&(a.first < b.first);
}

vector<pair<int, int>> Sort(unordered_map<int, int> &M)
{

    vector<pair<int, int>> A;

    for (auto &it : M)
    {
        A.push_back(it);
    }

    sort(A.begin(), A.end(), cmp);
    return A;
}

int mostFrequentEven(vector<int> &nums)
{
    unordered_map<int, int> map;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % 2 == 0)
            map[nums[i]]++;
    }
     vector<pair<int, int>> A = Sort(map);
    return A[0].first;
   
}
int main()
{
}