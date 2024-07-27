#include <bits/stdc++.h>
using namespace std;

 
int main() {
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        long long int ans = a + b;

        for(int i = 2;i<= min((int)1e5,max(a,b));i++){
            long long int num = ceil((double)a/i) + ceil((double)b/i) + i-1;
            ans = min(ans,num); 
        }
       cout<<ans<<endl;
    }
}
