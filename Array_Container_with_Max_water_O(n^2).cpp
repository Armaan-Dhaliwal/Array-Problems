#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

    vector<int> Next_Big(vector<int> &height,vector<int> &next_big ){
        int n=height.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(height[j]>=height[i]){
                    next_big[i]=j;
                }
            }  
        }
        return next_big;
    }

    vector<int> Prev_Big(vector<int> &height,vector<int> &prev_big ){
        int n=height.size();
        for(int i=n-1;i>=0;i--){
            for(int j=i;j>=0;j--){
                if(height[j]>=height[i]){
                    prev_big[i]=j;
                }
            }  
        }
        return prev_big;
    }

    int maxArea(vector<int>& height) {
        int n=height.size();
        vector<int> next_big(n);
        vector<int> prev_big(n);
        next_big=Next_Big(height,next_big);
        prev_big=Prev_Big(height,prev_big);
        
        vector<int> res(n);
        for(int i=0;i<n;i++){
            res[i]=max({height[i]*(next_big[i]-i),height[i]*(i-prev_big[i])});
        }

        int max_area=-999;
        for(int i=0;i<n;i++){
            if(res[i]>max_area){
                max_area = res[i];
            }
        }
        return max_area;
    }
};