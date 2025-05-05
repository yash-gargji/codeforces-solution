#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
        int n;
        cin>>n;
        int ma = 0;
        int mi  = 1e9 + 1;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            ma = max(ma,num);
            mi = min(mi,num);
        }
        cout<<ma - mi<<endl;
     }
}