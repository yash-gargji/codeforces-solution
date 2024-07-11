#include<bits/stdc++.h>
using namespace std;

  void func(int l,int r,string &ans,char a){
        int num;
        cout<<"?"<<" "<<a<<" "<<l<<" "<<r<<endl;
        cin>>num;
        if(num == 0){
             return;
        }
        if(num == 1 && r - l + 1 == 1){
            ans[l-1] = a;
            return;
        }
        int mid = (r + l)/2;
        func(l,mid,ans,a);
        func(mid+1,r,ans,a);
  }

int main(){   
      int n; 
      cin>>n;
      string ans(n,' ');

      for(int i = 0;i<26;i++){
         char a = 'a' + i;
         func(1,n,ans,a);
      }
      cout<<"! "<<ans<<endl;
}