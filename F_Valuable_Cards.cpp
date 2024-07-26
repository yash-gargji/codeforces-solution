#include<bits/stdc++.h>
using namespace std;

void func(int k,map<int,int>&m,int x){
     
     for(auto it = m.rbegin();it != m.rend();it++){
         long long int num = it->first*k*1ll;
         if(x%num == 0){
            m[(int)num] = 1;
         }
     }
}

int main(){
    int t;
    cin>>t;

    while(t--){
       int n,x;
       cin>>n>>x;
       vector<int>v(n);

       for(int i = 0;i<n;i++){
          cin>>v[i];
       }
       int ans = 1;
       map<int,int>m;
       m[1] = 1;

       for(int i = 0;i<n;i++){
           if(v[i] != 1 && x % v[i] == 0){
               func(v[i],m,x);
               if(m.find(x) != m.end()){
                  ans++;
                  map<int,int>curr;
                  curr[1] = 1;
                  curr[v[i]] = 1;
                  m = curr;
               }
           }
       }
      cout<<ans<<endl;
    }
}