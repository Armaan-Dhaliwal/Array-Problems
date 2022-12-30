/*Problem Description:
You have been given an integer array/list(ARR) of size N. Where N is equal to [2M + 1].
Now, in the given array/list, 'M' numbers are present twice and one number is present only once.
You need to find and return that number which is unique in the array/list.
Note:
Unique element is always present in the array/list according to the given condition.

Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

First line of each test case or query contains an integer 'N' representing the size of the array/list.

Second line contains 'N' single space separated integers representing the elements in the array/list.

Output Format :
For each test case, print the unique element present in the array.

Output for every test case will be printed in a separate line.

Constraints :
1 <= t <= 10^2
0 <= N <= 10^6*/

#include<iostream>
using namespace std;

int main(){
    int test;
    cout<<"Enter number of test cases: "<<endl;
    cin>>test;

    for (int i = 0; i < test; i++)
    {   
        int n;
        cout<<"Enter Number of elements: "<<endl;
        cin>>n;
        int arr[n];
        for (int i = 0; i < n; i++)
        {
            cin>>arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            int count=0;
           int current = arr[i];
        
        
        for (int j = 0; j < n; j++)
        {
            if(arr[j]==current){
                count++;
            }
        }
        if(count==1){
            cout<<arr[i]<<endl;
        }
        
        }
        
        

    }
    
}