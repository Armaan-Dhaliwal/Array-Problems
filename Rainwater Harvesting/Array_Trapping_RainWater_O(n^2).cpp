#include<iostream>
#include<stack>
#include<vector>
using namespace std;
class Solution {
public:

    void next_biggest(vector<int>& height,vector<int>& res){
        int size=height.size();

        for(int i=0;i<size;i++){
            int temp=height[i];
            for(int j =i+1;j<size;j++){
                if(height[j]>=temp){
                    res[i]=height[j];
                    temp=height[j];
                }
            }
        }
    }

    void prev_biggest(vector<int>& height, vector<int>& res){
        int size=height.size();

        for(int i=size-1;i>=0;i--){
            int temp=height[i];
            for(int j =i-1;j>=0;j--){
                if(height[j]>=temp){
                    res[i]=height[j];
                    temp=height[j];
                }
            }
        }
    }

    int trap(vector<int>& height) {
        int size = height.size();
        vector<int> next_big(size,0);
        vector<int> prev_big(size,0);
        prev_biggest(height,prev_big);
        next_biggest(height,next_big);

        int water=0;
        for(int i=0;i<size;i++){
            int current = height[i];
            int min = 0;
            if(next_big[i]<prev_big[i]){
                min=next_big[i];
            }
            else{
                min=prev_big[i];
            }

            if(min-current>0){
                water+=min-current;
            }
        }

        return water;
    } 

};