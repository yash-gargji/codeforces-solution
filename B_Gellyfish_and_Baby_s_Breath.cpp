#include<bits/stdc++.h>
using namespace std;
#define int long long 

long long binpow(long long a, long long b, long long m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

signed main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int mod = 998244353;
 

         vector<int>p(n),q(n);

         for(int i = 0;i<n;i++){
              cin>>p[i];
         }
         for(int i = 0;i<n;i++){
              cin>>q[i];
         }
         int ma1 = -1,in1 = -1,t1 = -1;
         int ma2 = -1,in2 = -1,t2 = -1;

         for(int i = 0;i<n;i++){
             if(p[i] > ma1){
                ma2 = ma1;
                in2 = in1;
                t2 = t1;
                ma1 = p[i];
                t1 = 0;
                in1 = i;
             }
             else if(p[i] > ma2){
                   ma2 = p[i];
                   t2 = 0;
                   in2 = i;
             }
             if(q[i] > ma1){
                ma2 = ma1;
                in2 = in1;
                t2 = t1;
                ma1 = q[i];
                t1 = 1;
                in1 = i;
             }
             else if(q[i] > ma2){
                   ma2 = q[i];
                   t2 = 1;
                   in2 = i;
             }
             if(ma1 > ma2){
                int num = 0;
                if(t1 == 0){
                    num = q[i-in1];
                }
                else 
                  num = p[i - in1];
                cout<<(binpow(2,ma1,mod) + binpow(2,num,mod)) % mod<<" ";
             }
             else {
                int num = 0;
                if(t1 == 0){
                    num = q[i-in1];
                }
                else 
                  num = p[i - in1];
                if(t2 == 0){
                    num = max(num,q[i-in2]);
                }
                else 
                  num = max(num,p[i - in2]);
                cout<<(binpow(2,ma1,mod) + binpow(2,num,mod)) % mod<<" ";
             }
         }
        cout<<endl;
    }
}  