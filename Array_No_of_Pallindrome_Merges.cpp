#include<iostream>
#include<stack>
#include<vector>
#include<algorithm>
using namespace std;

int mergeCounter(vector<int> vec){
    int n=vec.size();
    int i=0;
    int j=n-1;
    int count=0;
    while(j>i){
        if(vec[i]==vec[j]){
            i++;
            j++;
        }

        if(vec[i]>vec[j]){
            vec[j-1]=vec[j]+vec[j-1];
            j--;
            count++;
        }

        if(vec[j]>vec[i]){
            vec[i+1]=vec[i]+vec[i+1];
            i++;
            count++;
        }
    }
    return count;
}

int main(){
    vector<int> vec{8,10,11,1};
    int count = mergeCounter(vec);
    cout<<"Count is: "<<count<<endl;
}