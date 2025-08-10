#include<bits/stdc++.h>
using namespace std;

int main(){   
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        int prev = -1;
        long long sum = 0;
        long long ans = 0;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            if(num > prev)
               sum = sum + 1;
            else 
              sum = sum + i + 1;
            ans += sum;
            prev = num;
        }
        cout<<ans<<endl;
    }
}