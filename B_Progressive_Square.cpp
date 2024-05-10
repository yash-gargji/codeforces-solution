#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int c,d;
         cin>>c>>d;
          
         map<int,int>m;
         for(int i = 0;i<n*n;i++){
             int num;
             cin>>num;
            m[num]++;
         }
         vector<int>v(n*n);
         int flag = 1;
          auto it = m.begin();
          for(int i = 0;i<n;i++){
               if(i == 0){
                v[i] = it->first;
                m[it->first]--;
               } 
               else {
                 int  num = v[i-1] + d;
                 if(m[num] != 0){
                    v[i] = num;
                    m[num]--;
                 }
                 else {
                    flag = 0;
                    break;
                 }
             }   
              for(int j = 1; j<n;j++){
                  int num = v[i] + j*c;
                  if(m[num] != 0){
                    v[j*n + i] = num;
                    m[num]--;
                 }
                 else {
                    flag = 0;
                    break;
                 }
              }
              if(flag == 0){
                break;
              }
          }
         if(flag){
              cout<<"YES\n";
         }
         else{
            cout<<"NO\n";
         }
    }
}