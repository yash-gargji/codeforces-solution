#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
       int n;
       cin>>n;

        int arr[n];
        vector<int>vis(n+1);
        int mi = -1;
        int ma = -1;

        for(int i = 0;i<n;i++){
            cin>>arr[i];
            vis[arr[i]] = 1;
            if(arr[i] == 1)
              mi = i + 1;
            if(arr[i] == n)
               ma = i+1;
        }
        int num = -1;
        for(int i = 1;i<= n;i++){
            if(!vis[i])
              num = i;
        }
        if(num != -1){
           int k;
           int x = (num == 1 ? 2 : 1);
           cout<<"? "<<num<<" "<<x<<endl;
           cin>>k;
           if(k != 0){
              cout<<"! B\n";
           }
           else{
              cout<<"! A\n";
           }
           continue;
        }
        int k;
        cout<<"? "<<mi<<" "<<ma<<endl;
        cin>>k;
        if(k > n-1)
          cout<<"! B\n";
        else if(k < n-1)
           cout<<"! A\n";
        else{
           cout<<"? "<<ma<<" "<<mi<<endl;
           cin>>k;
           if(k == n-1)
          cout<<"! B\n";
           else 
           cout<<"! A\n";
        }
    }
}