#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int l,r;   
         cin>>l>>r;
         l--;
         int ans = 0;
         int num = 15;
         int p = 0;
         vector<int>v = {2,3,5,7};

         while(num){
            int ind = 0,count = 0;
            int k = 1;

            while((1 << ind) <= num){
               if(((1 << ind) & num)){
                  count++;
                  k = k * v[ind];
               }
               ind++;
            }
            if(count % 2){
               ans += r/k - l/k;
            }
            else {
                 ans += l/k - r/k;
            }
            num--;
         }
        cout<<r - l - ans<<endl;
    }
    
     
}