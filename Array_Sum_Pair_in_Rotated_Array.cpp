#include<iostream>
#include<stack>
#include<vector>
using namespace std;

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
         int min_index;
        if(n==1){
            min_index =  nums[0];
        }
        min_index=BinarySearch(nums,0,n-1);
        return min_index;
    }


int findPairSum(vector<int> arr, int target)
{   
    int n=arr.size();
    int min_index=findMin(arr);
    if(min_index==-1){
        min_index=0;
    }
    int i=min_index;
    int j=min_index-1;
    bool flag=false;

    if(j<0){
            j=n-1;
        }
        if(i>=n){
            i=0;
        }
        int sum;
        int count=n;

    while(count>1){

        sum=arr[i]+arr[j];
        if(sum==target){
            flag=true;
            break;
        }

        if(sum<target){
            i++;
        }

        else if(sum>target){
            j--;
        }
        if(j<0){
            j=n-1;
        }
        if(i>=n){
            i=0;
        }
        count--;
    }

    if(flag==true){
        cout<<"YES"<<endl;
    }
    if(flag==false){
        cout<<"NO"<<endl;
      }
    
    return 0;
}

int main(){
    int target=2;
    vector<int> vec{8,10,11,1};
    int no_value = findPairSum(vec,target);
}