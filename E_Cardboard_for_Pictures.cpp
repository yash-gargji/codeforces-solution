 #include <bits/stdc++.h>
using namespace std;
 #define ll long long int

ll solveQuadratic(long double a, long double b, long double c) {
    long double discriminant = b * b - 4 * a * c;

    if (discriminant >= 0) {

        long double sqrtDiscriminant = std::sqrt(discriminant);
        ll root = (-b + sqrtDiscriminant) / (2 * a);
        return root;
    }
}
 
int main(){
    int t;
    t = 1;
    cin>>t;
    while (t--){

        ll n,c;
    cin>>n>>c;

      long double ans = 0;
    long double fun = 0;

    for(int i=0;i<n;i++){
        ll num;
        cin>>num;
        ans = ans + num*num;
        fun = fun + 4*num;
    }
        ll k = solveQuadratic(4*n,fun,ans-c);
       cout<<k<<endl;
    }
       
    return 0;
}