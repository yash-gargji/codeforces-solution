#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
       int t;
       cin>>t;
       while(t--){
             int n;
             cin>>n;
             int s;
             cin>>s;
            int arr[n];
            int ma = 0;
            for(int i = 0;i<n;i++){
                cin>>arr[i];
                ma = max(ma,arr[i]);
            }
            sort(arr,arr+n);
            int h  = 0;
            for(int i  = 1;i<=ma;i++){
                int flag = 0;
                   for(int j = 0;j<n;j++){
                    if(arr[j] == i){
                        flag = 1;
                        break;
                    }
                 }
                  if(flag == 0){
                    h += i;
                  }
            }
             if(s < h){
                cout<<"NO\n";
                continue;
             }
             int i = 1;
             while(h < s){
                  h += ma+i;
                  i++;
             }
             if(h != s){
                cout<<"NO\n";
             }
             else{
                cout<<"YES\n";
             }
       }
}