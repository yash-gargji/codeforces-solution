#include<bits/stdc++.h>
using namespace std;

int main(){
        int n,k,q;
        cin>>n>>k>>q;

        vector<int>d(200001,0);
        for(int i = 0;i<n;i++){
              int a,b;
              cin>>a,b;
              d[a-1] += 1;
              d[b] -= 1;
        }
        
       for(int i = 1;i<200001;i++){
             d[i] += d[i-1];
       }
       for(int i = 0;i<20001;i++){
           if(d[i] >= k){
               d[i] = 1;
           }
           else{
                d[i] = 0;
           }
       }
     for(int i = 0;i<200001;i++){
        d[i] = d[i] + d[i-1];
     }
     for(int i = 0;i<q;i++){
        int a,b;
        cin>>a>>b;
          if(a == 1){
               cout<<d[b-1]<<endl;
          }
          else{
            cout<<d[b-1] - d[a-2]<<endl;
          }
     }
}