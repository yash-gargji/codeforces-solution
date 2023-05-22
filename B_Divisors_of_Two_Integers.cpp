#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
       vector<int>v;
       map<int,int>m;
       for(int  i= 0 ;i<t;i++){
        int num;
        cin>>num;
        m[num]++;
        v.push_back(num);
       }
       sort(v.begin(),v.end());
       cout<<v[t-1]<<" ";
       int l = 100000;
       int y = v[t-1];
             int count = 0 ;
              for(int j = t-1; j>=0;j-- ){
                   if(y%v[j] == 0 && v[j] != l){
                    l = v[j];
                       m[v[j]]--;
                   }
              }
                for(int j = t-1; j>=0;j-- ){
                   if(m[v[j]] != 0){
                       cout<<v[j];
                       return 0;
                   }
              }

          return 0;   
             }
      
