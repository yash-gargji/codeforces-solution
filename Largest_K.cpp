#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         vector<int>v(n+1);
         int ans = 0;

         for(int i = 0;i<n;i++){
              int num;
              cin>>num;
              v[num]++;
         }
         int sum = 0;
         sort(v.begin(),v.end());

         for(int i = n; i>= 0;i--){
            if(v[i] == 0){
                break;
            }
             sum += v[i];
             ans = max(ans,(sum / (n - i + 1)) * (n - i + 1));
         }
        cout<<ans<<endl;
    }
}