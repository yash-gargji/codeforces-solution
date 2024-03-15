#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n);
        int flag = 0;
        for(int i = 0;i<n;i++){
            cin>>v[i];
        }

        for(int i = 0;i<n;i++){
             if(v[i] == 0) continue;
             if(i + 2 >= n || v[i] < 0) 
             {
              cout<<"NO\n";
              flag = 1;
              break;
             }
            int num = v[i];
            v[i] = 0;
            v[i+1] -= 2*num;
            v[i+2] -= num;
        }
         if(flag == 0) cout<<"YES\n";
    }
}