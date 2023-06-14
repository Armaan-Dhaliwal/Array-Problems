#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int max_till_here=nums[0];
        int min_till_here=nums[0];
        int maximum=nums[0];

        for(int i=1;i<n;i++){
           int temp = max({ nums[i], nums[i] * max_till_here, nums[i] * min_till_here });
            min_till_here = min({nums[i],min_till_here*nums[i],max_till_here*nums[i]});
            max_till_here = temp;
            maximum=max({maximum,max_till_here});
        }
    return maximum;
    }
};