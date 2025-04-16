#include <bits/stdc++.h>
using namespace std;
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
{

    if (m == 0)
    {
        nums1 = nums2;
    }

    else if (n != 0)
    {

        vector<int> nums3;
        int i = 0, j = 0;
        while (i < m)
        {

            if (nums1[i] < nums2[j])
            {
                nums3.push_back(nums1[i]);
                i++;
            }
            else if (nums1[i] > nums2[j])
            {
                nums3.push_back(nums2[j]);
                j++;
            }
            else
            {
                nums3.push_back(nums1[i]);
                i++;
                nums3.push_back(nums2[j]);
                j++;
            }
        }

        while (j < n)
        {
            nums3.push_back(nums2[j]);
            j++;
        }

        nums1 = nums3;
    }
}
int main()
{
    vector<int> nums1 = {1, 2, 3, 4, 0, 0, 0, 0};
    vector<int> nums2 = {2, 4, 5};
    int m = 4, n = 3;
    merge(nums1, m, nums2, n);
}