#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){
    int t=1;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)cin>>a[i];
        sort(a,a+n);
        cout<<a[n/2]<<endl;
    }
    return 0;
}