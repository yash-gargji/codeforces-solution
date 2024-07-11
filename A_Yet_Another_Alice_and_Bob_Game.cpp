#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
          int n;
          cin>>n;
         long long int ans = 0;
         vector<int>even,odd;

         for(int i  =0;i<n;i++){
             int num;
             cin>>num;
             if(num%2 == 1){
                odd.push_back(num);
                ans += num;
             }
             else{
                even.push_back(num);
             }
         }
         sort(odd.begin(),odd.end());
         sort(even.begin(),even.end());
         int r = even.size()-1;

         while(r >= 0){
            ans -= even[r];
            r--;
            if(odd.size()  >= 1 && r >= 0){
              ans += even[r];
              r--;
            }
         }
        cout<<ans<<endl;
    }
}