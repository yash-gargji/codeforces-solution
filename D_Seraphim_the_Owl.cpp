#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;

        long long int a[n], b[n];

        for(int i = 0;i<n;i++){
            cin>>a[i];
        }
        for(int i = 0;i<n;i++){
            cin>>b[i];
        }
        for(int i = n-2;i >= 0;i--){
            long long int num = min(a[i+1],b[i+1]);
            a[i] += num;
            b[i] += num;
        }
        cout<<*min_element(a,a+m)<<endl;
    }
}