#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int max_area=-100;
        int n=height.size();
        int si=0;
        int ei=n-1;

        while(si<ei){
            int temp_area = (ei-si)*min({height[si],height[ei]});
            if(temp_area>max_area){
                max_area = temp_area;
            }

            if(height[si]<height[ei]){
                si++;
            }
            else{
                ei--;
            }
        }
        return max_area;

    }
};