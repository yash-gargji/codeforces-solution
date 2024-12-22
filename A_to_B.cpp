#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int x1,y1,z1,x2,y2,z2,k;
         cin>>x1>>y1>>z1>>x2>>y2>>z2>>k;
         vector<int>v = {abs(x1 - x2),abs(y1 - y2),abs(z1 - z2)};
         
         sort(v.begin(),v.end());
         if((v[0] + v[1])*k >= v[2] - k){ 
             cout<<v[0] + v[1] + v[2]<<endl;
         }
         else{
            int sum = k;
            v[2] -= k;
            sum += (k+1)*(v[0] + v[1]);
            v[2] -= k*(v[0] + v[1]);
            int num = ceil((double)v[2]/k);
            sum += v[2] + num + num % 2;
            cout<<sum<<endl;
         }
         
    }
}