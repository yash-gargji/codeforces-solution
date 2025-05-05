#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n,x;
       cin>>n>>x;
       
       vector<int>ans(n);
       
       int num = 0;
       int ind = -1;

       for(int i = 0;i<n;i++){
           int f = 0;
           int j = 0;

           while( ((1 << j) <= i)){
               int a = (1 << j) & x;
               int b = ((1 << j) & i);
               if(a == 0 && b != 0){
                 f = 1;
                 break;
               }
           }
           if(f){
            ind = i;
            break;
           }
           j++;
           num = num | i;
           ans[i] = i;
       }
       if(ind != -1){
          for(int i = ind;i<n;i++){
               ans[i] = x;
          }
       }
       else if(num != x){
          ans[n-1] = x;
       }

       for(int i = 0;i<n;i++){
          cout<<ans[i]<<" ";
       }
       cout<<endl;
    }
}