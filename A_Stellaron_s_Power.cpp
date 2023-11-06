#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     
         int n,m;
         cin>>n>>m;

        int count = 0;

        while(n <= m){
            n = n*3;
            m = m*2;
            count++;
        }
        cout<<count;    
}