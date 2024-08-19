#include<bits/stdc++.h>
using namespace std;

int main(){
   int t;
   cin>>t;
   while(t--){
     long long int n,c;
     cin>>n>>c;
     vector<pair<int,int>>v(n);

     for(int i = 0;i<n;i++){
         int num;
         cin>>num;
         v[i].first = num + min(1ll*i+1,n - i);
         v[i].second = i;
     }
     int count = 0;
     int min_ind = INT_MAX;
     for(int i = 0;i<n;i++){
        if(v[i].first <= c){
            count++;
            c -= v[i].first;
            min_ind = min(min_ind,v[i].second); 
        }
        else
         break;
     }
     if(count == 0){
         cout<<count<<endl;
         continue;
     }
   }
}