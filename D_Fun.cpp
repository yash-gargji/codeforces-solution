#include <bits/stdc++.h>
using namespace std;

long long func(int n,int x,int last,int ind){
     long long num = 0;

     for(int i = 1;i<= last;i++){
         int a = x - ind - i;
         int b = (n - ind*i)/(ind + i);
         num += max(0,min(a,b));
     }
    return num;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
         long long n, x;
         cin >> n >> x;
        long long ans = 0;

        for (int i = 1;i<= x;i++) {
            ans += func(n,x,min(x - i,n/i),i);
        }
        cout<<ans<<endl;
    }
    return 0;
}
