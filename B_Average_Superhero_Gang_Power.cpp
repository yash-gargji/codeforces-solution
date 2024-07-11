#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k,m;
    cin>>n>>k>>m;
    vector<int>v(n);
    double sum = 0;
    
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        v[i] = num;
        sum += num;
    }
     double ans = (sum + min((double)m,(double)k*n))/n;
     sort(v.begin(),v.end());
     
     for(int i = 0;i<n;i++){
         if(i == n-1){
            double p = sum + min(m - i,k);
            ans = max(ans,p);
            continue;
         }
        if(i + 1 > m){
           break;
        }
        sum = sum - v[i];
        double p = sum + min(double(m - i - 1),(double)k*(n - i - 1));
        ans = max(ans,p/(n-i-1));
     }
     cout<<fixed<<setprecision(9)<< ans << endl;
}