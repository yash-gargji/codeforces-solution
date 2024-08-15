#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){

        int n;
        cin>>n;
        int arr[n];
        vector<int>vis(n);
        int ans = 1;
        int num;
        cin>>num;
        num--;
        vis[num] = 1;
        

        for(int i = 0;i<n-1;i++){ 
            int k;
            cin>>k;
            k--;
            if((k != 0 && vis[k-1]) || (k != n-1 && vis[k+1])){
                vis[k] = 1;
               continue;
            }
            else{
               ans = 0;
            }
        }
        if(ans == 0){
              cout<<"NO\n";
        }
        else{
            cout<<"YES\n";
        }
    }
}    