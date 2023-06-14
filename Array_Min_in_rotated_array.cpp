#include<iostream>
#include<stack>
#include<vector>
using namespace std;

class Solution {
public:

    int BinarySearch(vector<int>& nums, int si,int ei){
        int mid=(si+ei)/2;
        if(ei-si==1){
            if(nums[ei]<nums[si]){
                return ei;
            }
            else{
                return -1;
            }
        }

        int num1=BinarySearch(nums,si,mid);
        int num2=BinarySearch(nums,mid,ei);
        if(num1!=-1){
            return num1;
        }
        return num2;
    }

    int findMin(vector<int>& nums) {
        int n=nums.size();
        if(n==1){
            return nums[0];
        }
        int min_index=BinarySearch(nums,0,n-1);
        if(min_index!=-1){
            return nums[min_index];
        }
        else{
            return nums[0];
        }
    }
};
int main(){
    Solution obj;
    vector<int> vec{11,13,15,17};
    cout<<"Min is: "<<obj.findMin(vec);
}