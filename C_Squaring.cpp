#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
         long long ans = 0,last = 0;
         int n;
         cin>>n;
         vector<int>v(n);

         for(int i = 0;i<n;i++){
             cin>>v[i];
         }
         for(int i = 1;i<n;i++){
            if(v[i] == 1 && v[i-1] > 1){
                ans = -1;
                break;   
            }
            int a = 0,b = 0;
            if(v[i-1] == 1)
              continue;
            if(v[i] < v[i-1]){
                a += ceil(log2((log(v[i-1]) / log(v[i]))));
            }
            else if(v[i-1] < v[i]){
               b += (log2((log(v[i]) / log(v[i-1]))));
            }
            if(a > 0)
              last += a;
             else {
               last = max(0ll,last - b);
             }
            ans += last;
         }
        cout<<ans<<endl;
       
    }
}