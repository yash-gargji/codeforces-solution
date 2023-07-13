#include<bits/stdc++.h>
using namespace std;
   void solve(){
        int k;
          cin>>k;
            if(k == 1){
                cout<<"1"<<endl;
                return ;
            }
            if(k == 2){
                cout<<"1 2"<<endl;
                return;
            }
            int p[k];

            p[0] = 2;
            
            
            int l = 4;
            p[k-1] = 3;
            for(int i = k/2+1;i<k-1;i++){
                     p[i] = l;
                     l++;
            }
            for(int i = k/2-1;i>=1;i--){
                  p[i] = l;
                  l++;
            }
            p[k/2] = 1;
            for(int i = 0;i<=k-1;i++){
                cout<<p[i]<<" ";
            }

            cout<<"\n";
   }
int main(){
     
      int t;
      cin>>t;
      
      while(t--){
           solve();
      }
     
}