#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        set<int>st;

        for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             st.insert(num);
        }
      if(st.size() >= 3){
        cout<<"NO\n";
      }
      else if(st.size() == 1){
          cout<<"YES\n";
      }
      else{
         if(*st.begin() == 0){
            cout<<"YES\n";
         }
         else{
            cout<<"NO\n";
         }
      }
    }
}