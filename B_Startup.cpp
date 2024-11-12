#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n,k;
         cin>>n>>k;
        vector<int>l(k);
        int x=k;
         for(int i = 0;i<k;i++){
            int a,b;
            cin>>a>>b;
            l[a-1]+=b;
        }
        sort(l.begin(),l.end());
        reverse(l.begin(),l.end());
        long long  sum =0;
        for(int i=0;i<min(n,x);i++){
            sum+=l[i];
        }
        cout<<sum<<endl;
     }
}