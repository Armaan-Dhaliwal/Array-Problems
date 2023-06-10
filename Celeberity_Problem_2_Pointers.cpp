#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
    int celebrity(vector<vector<int> >& M, int n) 
    {
        int i=0;
        int j=n-1;
        while(i<j){
            if(M[j][i]==1){
                j--;
            }
            
            else{
                i++;
            }
        }
        int cand= i;
        for(int p=0;p<n;p++){
            if(M[cand][p]==1){
                cand = -1;
                break;
            }
        }
        
        if(cand!=-1){
            for(int p=0;i<n && p!=cand;p++){
                if(M[p][cand]==0){
                    cand = -1;
                    break;
                }
            }
        }
        return cand;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<"result is ";
        cout<<ob.celebrity(M,n)<<endl;

    }
}
