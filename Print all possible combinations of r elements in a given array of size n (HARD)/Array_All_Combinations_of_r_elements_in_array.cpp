#include<iostream>
#include<algorithm>
using namespace std;

void helper(int arr[],int n, int r, int index,int set[],int i){

    if(index==r){
        for(int j=0;j<r;j++){
            cout<<set[j]<<" ";
        }
        cout<<endl;
        return;
    }

    //all elements have been accessed 
    if(i>=n){
        return ;
    }

    // Proning Recursion tree paths of remaining elements less than required r
    if(r-index>n-i+1){
        return;
    }

    set[index]=arr[i];
    while(arr[i]==arr[i+1]){
        i++;
    }
    helper(arr,n,r,index+1,set,i+1);
    helper(arr,n,r,index,set,i+1);
}

void printCombination(int arr[],int n, int r){
    int *set = new int(r);
    helper(arr,n,r,0,set,0);
}

int main(){
    
    int arr[] = {1, 2, 2};
    int n = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+n);
    int r = 2;
    printCombination(arr, n, r);
    return 0;
}