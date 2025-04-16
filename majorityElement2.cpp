#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &nums) {
    unordered_map<int, int> map;
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        map[nums[i]]++;
    }
    int x = nums.size() / 3;
    for (auto i = map.begin(); i != map.end(); i++) {
        if (i->second > x) {
            result.push_back(i->first);
        }
    }
    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> result = majorityElement(nums);
    for (int num : result) {
        cout << num << " ";
    }
    return 0;
}
