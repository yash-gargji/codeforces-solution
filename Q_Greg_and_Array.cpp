#include<bits/stdc++.h>
using namespace std;
    
int main(){

   int n,m,k;
   cin>>n>>m>>k;

   pair<pair<long long int,long long int>,long long int>p[m];
   long long int arr[n];
   for(int i = 0;i<n;i++){
    cin>>arr[i];
   }  
   vector<long long int>diff(n+1,0);
   vector<long long int>ex(m+1,0);
   for(int i = 0;i<n;i++){
    if(i == 0){
        diff[i] = arr[i];
    }
    else{
        diff[i] = arr[i] - arr[i-1];
    }
   }
   for(int i = 0;i<m;i++){
        long long int a,b,c;
        cin>>a>>b>>c;
        p[i] = {{a-1,b-1},c};
   }
   for(int i = 0;i<k;i++){
      long long int a,b;
      cin>>a>>b;
      ex[a-1] = ex[a-1] + 1;
      ex[b] = ex[b] - 1;
   }
    
    for(int i = 1; i < m; i++){
        ex[i] = ex[i] + ex[i-1];
    }

for(int i = 0; i < m; i++){
    if(ex[i] <= 0){
        continue;
    }
    else{
        long long int num = (p[i].second) * ex[i];
       long long int l = p[i].first.first;
        long long int r = p[i].first.second;
        diff[l] += num;
        diff[r+1] -= num;
    }
}

   for(int i  = 0;i<n;i++){
       if(i == 0){
        cout<<diff[i]<<" ";
       }
       else{
        diff[i] += diff[i-1];
           cout<<diff[i]<<" ";
       }
   }
} 