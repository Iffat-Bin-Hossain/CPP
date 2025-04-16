#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> &a,
         pair<int, int> &b)
{
    return a.second > b.second;
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
int majorityElement(vector<int> &nums)
{
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++)
    {
        map[nums[i]]++;
    }
    vector<pair<int, int>> A = Sort(map);
    return A[0].first;
}
int main()
{
    vector<int> nums={2,2,1,1,1,2,2,3,3,3,3};
    cout<<majorityElement(nums);
}