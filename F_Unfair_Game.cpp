#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int a ,b,c,d;
        cin>>a>>b>>c>>d;

       cout<<max(a/2+b/2+c/2+d/2,min(min(a,b),c) +d/2)<<endl;
    }
}