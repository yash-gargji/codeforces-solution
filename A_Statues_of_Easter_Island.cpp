#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v1(n),v2(n);

    for(int i = 0;i<n;i++){
       cin>>v1[i]>>v2[i];
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    long long int ans = 0;
    int pos = 1;

    for(int i = 0;i<n;i++){
         ans += abs(pos - v1[i]) + abs(pos - v2[i]);
         pos++;
    }
    cout<<ans<<endl;
    
}