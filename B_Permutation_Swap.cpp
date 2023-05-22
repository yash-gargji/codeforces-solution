#include<bits/stdc++.h>
using namespace std;

 int gcd(int a, int b) {
   if (b == 0)
   return a;
   return gcd(b, a % b);
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        int arr[a];
        vector<int>v;
        for(int i = 0;i<a;i++){
          cin>>arr[i];
          if(max(i+1,arr[i]) - min(i+1,arr[i]) > 0){  
            v.push_back(max(i+1,arr[i]) - min(i+1,arr[i]));
        }
        }
        if(v.size() == 1){
            cout<<v[0]<<endl;
            continue;
        }
          sort(v.begin(),v.end());
        int ans = gcd(v[0],v[1]);
        for(int i = 2;i<v.size();i++){
           ans  = gcd(ans,v[i]);
        }
          cout<<ans<<endl;
        }
        
    return 0;
}