#include<bits/stdc++.h>
using namespace std;

int main(){
     int n,x;
     cin>>n>>x;
     vector<int>v(x+1);
     for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        v[num]++;
     }
     int ans = 1;
      for(int i = 1;i<x;i++){
        if(v[i] % (i+1)){
             ans = 0;
             break;
        }
        v[i+1] += v[i]/(i+1);
      }
     if(v[x] == 0)
        ans = 0;
      if(ans)
        cout<<"Yes";
      else 
        cout<<"No";
}