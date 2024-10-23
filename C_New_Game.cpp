#include<bits/stdc++.h>
using namespace std;

long long func(long long x, long long y, long long mod) {
    long long result = 1;
    while (y > 0) {
        if (y % 2 == 1) {
            result = (result * x) % mod;
        }
        x = (x * x) % mod;
        y /= 2;
    }
    return result;
}

int main(){
    int t=1;
    while(t--){
        long long mod = 1e9 + 7;
         int n;
        cin >> n;
        vector<int> v1(n), v2(n);
        for (int i = 0; i < n; i++)
           cin >> v1[i];
        for (int i = 0; i < n; i++) 
           cin >> v2[i];
        
        for (int i = 0; i < n; i++) {
            if(v1[i] != v2[i]){
                cout<<func(2,v2[i],mod)<<endl;
            }
            else 
              cout<<"a"<<endl;
        }
    }
    return 0;
}