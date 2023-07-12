#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
using namespace std;

int main(){
    stack<int> s;
    cout<<"Enter ranked weights: "<<endl;
    vector<int> ranked;
    int rankele;
    cin>>rankele;
    while(rankele!=-1){
        ranked.push_back(rankele);
        cin>>rankele;
    }

    for(int i=0;i<ranked.size();i++){
        cout<<ranked[i]<<" ";
    }
    cout<<endl;

    cout<<"Enter unranked weights: "<<endl;
    vector<int> unranked;
    int unrankele;
    cin>>unrankele;
    while(unrankele!=-1){
        unranked.push_back(unrankele);
        cin>>unrankele;
    }


    for(int i=0;i<unranked.size();i++){
        cout<<unranked[i]<<" ";
    }
    cout<<endl;

    vector<int> aux(ranked.size()+unranked.size(),0);
    vector<int> res;
    
    for(int i=0;i<unranked.size();i++){
        while(ranked.size()!=0 && unranked[i]>ranked[ranked.size()-1]){
            s.push(ranked[ranked.size()-1]);
            ranked.pop_back();
        }
        ranked.push_back(unranked[i]);
        while(!s.empty()){
            ranked.push_back(s.top());
            s.pop();
        }
    }

    aux[0]=0;
    for(int i=1;i<ranked.size();i++){
        if(ranked[i-1]==ranked[i]){
            aux[i]=aux[i-1]+1;
        }
        else
        aux[i]=aux[i-1];
    }
    for(int i=0;i<aux.size();i++){
        cout<<aux[i]<<" ";
    }
    cout<<endl;

    
    cout<<"after insertion: "<<endl;
     for(int i=0;i<ranked.size();i++){
        cout<<ranked[i]<<" ";
    }
    cout<<endl;

    for(int i=0;i<ranked.size();i++){
        if(ranked[i]==unranked[unranked.size()-1]){
            int index=(i+1)-aux[i];
            res.push_back(index);
            unranked.pop_back();
        }
    }

    reverse(res.begin(),res.end());
    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }

}
// ranked = 120 100 100 90 60 
// unranked = 40 40 80

