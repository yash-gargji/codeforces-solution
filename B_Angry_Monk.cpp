 #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k;
        cin>>n>>k;
         vector<int>v(k);

         for(int i = 0;i<k;i++){
            cin>>v[i];
         }
         sort(v.begin(),v.end());

         long long ans = 0;

         for(int i = 0;i<k-1;i++){
            ans += 2*v[i] - 1;
         }
         cout<<ans<<endl;
    }
}