#include<bits/stdc++.h>
using namespace std;

#define int long long

signed  main(){
    int t;
    cin>>t;

    while(t--){
        int n,q;
        cin>>n>>q;
        vector<int>v(n);
        int sum = 0;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            sum += num;
            v[i] = sum;
        }
        for(int i = 0;i<q;i++){
            int l,r;
            cin>>l>>r;
            int num = ((r-1)/n - (l - 1)/n + 1);
            int a = num*sum;
            int lf = (l - 1)/n;
            int lp = l - lf*n;
            int lr = n - lf;
            if(lp > lr){
                a -= v[lf- 1] + v[lp - lr - 1];
                a -= (v[n-1] - v[lf - 1]);
            }
            else if(lp != 1){
                int k = v[lf + lp - 2];
                 if(lf != 0)
                   k -= v[lf-1];
                 a = a - k;
            }
            int rf = (r - 1)/n;
            int rp = r - rf*n;
            int rr = n - rf;
            if(rp > rr && num != 0 && rf != 0){
                 int k = v[lf - 1];
                 if(rp - rr - 1 != 0)
                   k -= v[rp - rr - 1];
                 a = a - k;
            }
            else if(rp != rr && num != 0){
                if(rf != 0)
                  a -= v[rf - 1];
                a -= (v[n-1] - v[rf + rp - 1]);
            }
           cout<<a<<endl;
        }
    }
}