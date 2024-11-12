#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long int n;
        cin>>n;
        if(n % 2 == 0)
          cout<<"2\n";
        else 
          cout<<2 + (n*n)/2<<endl;
    }
}