#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       long long int n,x;
       cin>>n>>x;
       int ans = 0;
       long long int num = 0;
       multiset<int>st;

       for(int i = 0;i<n;i++){
           int k;
           cin>>k;
           if(k >= x){
             ans++;
             num += k - x;
           }
           else{
              st.insert(x - k);
           }
       }
       for(auto it:st){
          if(it > num)
            break;
            ans++;
            num -= it;
       }
       cout<<ans<<endl;
    }
}