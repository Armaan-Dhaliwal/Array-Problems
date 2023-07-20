#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int minSwaps(vector<int>&nums)
	{
	    vector<pair<int,int>> vec;
	    for(int i=0;i<nums.size();i++){
	        vec.push_back({nums[i],i});
	    }
	    sort(vec.begin(),vec.end());
	    
	    int counter=0;
	    for(int i=0;i<nums.size();i++){
	        if(vec[i].second==i){
	            continue;
	        }
	        else{
	            counter++;
	            swap(vec[i],vec[vec[i].second]);
	            i--;   
	        }
	    }
	    return counter;
	}