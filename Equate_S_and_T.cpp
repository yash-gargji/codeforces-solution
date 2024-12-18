#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
         int n,m;
         cin>>n>>m;
         
         string a,b;
         cin>>a>>b;
         
         int flag = 1;
         int ind = 0;
         int count = 0;

         for(int i = 0;i<n;i++){
             if(a[i] == 'b'){
                 count++;
             }
             else 
              break;
         }
         for(int i = 0;i<m;i++){
             if(b[i] == 'b'){
                 count--;
             }
             else 
              break;
         }
         if(count != 0){
            cout<<"No\n";
            continue;
         }
         int v1 = 0,v2 = 0;
         for(int i = 0;i<n;i++){
            if(a[i] == 'b'){
                 continue;
            }
            v1++;
         }
         for(int i = 0; i < m; i++) {
             if(b[i] == 'a')
               v2++;
        }
       
         if(v1 != v2)
          cout<<"No\n";
         else
          cout<<"Yes\n";
     }
}