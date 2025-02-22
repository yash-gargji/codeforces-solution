#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int q;
        cin>>q;
        int arr[n];
        vector<vector<int>>b(n,vector<int>(30,-1));
        vector<int>suff(n+1);
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            int ind = 32 - __builtin_clz(arr[i]) - 1;
            for(int  j = 0;j<30;j++){
                if(ind >= j) 
                  b[i][j] = i;
                else if(i != 0){
                   b[i][j] = b[i-1][j];
                }
            }
        }
        for(int i = n-1;i >= 0;i--){
            suff[i] = arr[i] ^ suff[i+1];
        }
        while(q--){
           int x;
           cin>>x;
           int curr = n-1;

           while(curr >= 0){
              int num = x ^ suff[curr+1];
              int ind = __lg(num);
              if(ind == -1)
                break;
              curr = b[curr][ind];
              
            //  cout<<ind<<" "<<curr<<endl;
              num = x ^ suff[curr+1];
              if(curr == -1 || num < arr[curr])
                 break;
               curr--;
           }
           cout<<n-1-curr<<" ";
        }
       cout<<endl;
    }
}