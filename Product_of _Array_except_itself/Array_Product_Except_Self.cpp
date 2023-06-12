#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> back(n);
        vector<int> forward(n);
        vector<int> res(n);

        int prod=1;
        for(int i=n-1;i>=0;i--){
            prod *= nums[i];
            back[i]=prod;
        }

        // cout<<"back is: ";
        // for(int i=0;i<n;i++){
        //     cout<<back[i]<<" ";
        // }

        prod=1;
         for(int i=0;i<n;i++){
            prod *= nums[i];
            forward[i]=prod;
        }

        // cout<<"forward is: ";
        // for(int i=0;i<n;i++){
        //     cout<<forward[i]<<" ";
        // }

        res[0]=1*back[1];
    for(int i=1;i<n-1;i++){
            res[i]=forward[i-1]*back[i+1];
    }

        res[n-1]=forward[n-2]*1;
        return res;
    }
};