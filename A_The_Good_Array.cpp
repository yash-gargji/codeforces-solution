#include<bits/stdc++.h>
using namespace std;

int main(){
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
           int count = (n-1)/m + 1;
           if((n-1)%m != 0){
              count++;
           }
           cout<<count<<endl;
    }
    return 0;
}