#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m,k;
        cin>>n>>m>>k;
        if(m == 0 || n == m){
         cout<<"0\n";
         continue;
        }
        if(n/k>= m){
            cout<<m<<endl;
            continue;
        }
        int num = n/k;
        m = m - num;
        k = k-1;
        int o ;
        if(m%k){
           o = m/k +1;
        }
        else {
            o = m/k;
        }
         
        if(o == num){
            cout<<"0\n";
        }
        else{
            cout<<num-o<<endl;
        }
    }
    return 0;
}