#include <bits/stdc++.h>
using namespace std;
void rotate(vector<int> &nums, int k)
{
    for (int i = 0; i < k; i++)
    {
        nums.insert(nums.begin(), 0);
    }
    for (int i = 0; i < k; i++)
    {
        swap(nums[i+k-1], nums[nums.size() - 1 - i]);
    }
    vector<int>::const_iterator first = nums.begin();
    vector<int>::const_iterator last = nums.begin() + nums.size() - k;
    vector<int> newVec(first, last);
    for (int i = 0; i < newVec.size(); i++)
    {
        cout << nums[i] << " ";
    }
}
int main()
{
    vector<int> nums = {1, 2, 3, 4};
    rotate(nums, 2);
}