#include<iostream>
#include<vector>
using namespace std;

 int firstMissingPositive(vector<int>& nums) {
        int j=0;
        int res=-1;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if(nums[i]<=0){
                swap(nums[i],nums[j]);
                j++;
            }
        }
        
        for(int i=j;i<nums.size();i++){
            int index;
                if(nums[i]<0 && nums[i]<2147483646){
                    index = -1*nums[i]-1+j;
                }
                else if(nums[i]<2147483646){
                    index = nums[i]-1+j;
                }
               
                if(index>=j && index<n){
                    if(nums[index]>0){
                        nums[index]=-1*nums[index];
                    }
                }
        }

        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }
        
        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                res=i-j+1;
                break;
            }
        }

        cout<<res<<endl;
        if(res==-1){
            res=n-j+1;
        }
        return res;
    }

    int main(){
        int num;
        cin>>num;
        vector<int> nums;
        while(num!=-1){
            nums.push_back(num);
            cin>>num;
        }

        cout<<firstMissingPositive(nums)<<" is result "<<endl;
    }