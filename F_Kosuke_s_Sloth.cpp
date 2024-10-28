 #include<bits/stdc++.h>
 using namespace std;

long long get_pisano_period(long long m) {
    long long a = 1, b = 1, c = a + b;
    int i = 1;
    for (;;) {
        c = (a + b) % m;
        a = b;
        b = c;
        if (a == 0) return i + 1;
        i++;
    }
}
int main(){
    int t;
    cin>>t;

    while(t--){
        long long int n ,k;
        int mod = 1e9 + 7;
        cin>>n>>k;
        if(k == 1){
          cout<<n % mod<<"\n";
          continue;
        }
        cout<<((n % mod)*(get_pisano_period(k) % mod)) % mod<<endl;
    }
}