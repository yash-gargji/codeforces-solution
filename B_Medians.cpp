#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int k;
        cin>>k;

        if(n == 1){
             cout<<"1\n1\n";
             continue;
        }
        else if(k == 1 || k == n){
           cout<<"-1\n";
           continue;
        }
        else if(k % 2 == 0){
           cout<<"3\n";
           cout<<"1 "<<k<<" "<<k+1<<endl;
        }
        else{
            cout<<"3\n";
           cout<<"1 "<<k-1<<" "<<k+2<<endl;
        }
    }
}