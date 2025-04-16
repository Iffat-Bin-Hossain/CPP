#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(vector<int>& nums) {
        int temp=nums[0];
        vector<int> expected_Numbers;
        expected_Numbers.push_back(temp);
        for(auto i=nums.begin(); i!=nums.end(); i++) {
            if(*i !=temp){
                temp=*i;
                expected_Numbers.push_back(temp);
            }
        }
        int k=expected_Numbers.size();
        nums=expected_Numbers;
        return k;
    }
int main()   
{
    vector<int> nums={0,0,0,1,1,1,2,2,3,3,4,4,5,5,6};
    cout<<removeDuplicates(nums)<<endl;
    for(auto i=nums.begin(); i!=nums.end(); i++){
        cout<<*i<<" ";

    }

}