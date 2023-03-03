#include<iostream>
using namespace std;

int celebIndex(int M[][4], int size){
    int i = 0;
    int j = size-1;

    while (i<j)
    {  
        if(M[i][j] == 1){
            i++;
        }

        else{
            j--;
        }  
    }
    
    int candidate = j;
    
    for(int i =0; i<size ;i++){
        if( i!=candidate){
            if(M[candidate][i] == 1 || M[i][candidate] == 0){
                 return -1;
            }
     }
    }

    return candidate;
}

int main()
{   
    int M[4][4] = { { 0, 1, 0, 0 },
                    { 0, 0, 0, 0 },
                    { 0, 1, 0, 0 },
                    { 0, 1, 0, 0 } };
 
    int celebIdx = celebIndex(M, 4);
 
    if (celebIdx == -1)
        cout << ("No Celebrity");
    else {
        cout << "Celebrity ID " << celebIdx;
    }
    return 0;
}