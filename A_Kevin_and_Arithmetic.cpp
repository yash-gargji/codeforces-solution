#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int odd = 0;
        int even = 0;
        int ans = 0;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            if(num % 2 == 1)
              odd++;
            else{
               even++;
            }
        }
        if(even > 0 ){
            ans += odd + 1;
        }
        else{
           ans += odd-1;
        }
      cout<<ans<<endl;
    }
}