
#define lli long long int
#define vi vector <double>
#define vp vector <pair <double, double>>
#define MOD 1e9 + 7
#define yes cout << "YES\n"
#define no cout << "NO\n"

#include <bits/stdc++.h>
using namespace std;

void Input (vi &v, long double n){
    for (long double i = 0; i < n; i++){
       long double a; cin >> a;
        v.push_back(a);
    }
}

bool Comparator(const pair<lli,lli>& a, const pair<lli,lli>& b) {
}

double Solve (vector <pair  <long double, pair <long double,long double>>> &v) {
    long double u = 0, v1 = 0, ans = 0;
    for (long double i = 0; i<v.size(); i++) {
        ans += (u*v[i].second.second + v[i].first);
        v1 = u + v[i].second.first*v[i].second.second;
        u = v1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false), cin.tie(NULL); 
    long double n; cin >> n;
    vector <pair  <long double, pair <long double,long double>>> v;
    for (double i = 0; i<n; i++) {
        double a, t;
        cin >> a >> t;
        v.push_back({0.5*a*t*t,{a,t}});
    }

    long double def = Solve(v);
    sort (v.begin(),v.end());
    reverse(v.begin(),v.end());
    long double opt = Solve(v);
    cout << std::fixed << std::setprecision(1) << opt - def;
    return 0;
}