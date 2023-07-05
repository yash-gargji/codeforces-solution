#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int t;
   cin>>t;

   while(t--){
       long long int n,m;
        cin>>n>>m;
          map<int,int>mp;
          int k = 0;
          for(int i = 0;i<n;i++){
            int nu;
            cin>>nu;
            mp[nu-1]++;
          }
           int arr[m];
          for(int i = 0;i<m;i++){
            cin>>arr[i];
          }
          long long int sum = 0;
          for(auto it = mp.rbegin(); it != mp.rend();it++){
             long long int a = it->first;
             long long int b = it->second;
             long long int h;
             if(a<= k){
                h = arr[a]*b;
                sum += h;
                continue;
             }
             long long int num;
             int p = k;
             for(int i = k ;i< min(m,p+b);i++){
               k = i ;
                
                if(k > a){
                     num = p+b - i;
                    break;
                }
                else{
                     num = p+b - i-1;
                       sum+= arr[k];
                       k = k+1;
                }
             }
             h = num*arr[a];
             sum += h;
          }
          cout<<sum<<endl;
   }
}