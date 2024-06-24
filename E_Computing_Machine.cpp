#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;

      while(t--){
            int n;
            cin>>n;
          string s1,s2;
          cin>>s1>>s2;
          string sm1 = s1, sm2 = s2;
          vector<int>pre(n);

          for(int i = 0;i<n-2;i++){
              if(s1[i] == '0' && s1[i+2] == '0'){
                 sm2[i+1] = '1';
              }
          }
          for(int i = 0;i<n-2;i++){
              if(sm2[i] == '1' && sm2[i+2] == '1'){
                 sm1[i+1] = '1';
              }
          }
          pre[0] = (sm1[0] == '1');

          for(int i = 1;i<n;i++){
             if(sm1[i] == '1')
                pre[i] = 1;
              pre[i] += pre[i-1];
          }
          int m;
          cin>>m;

          for(int i = 0;i<m;i++){
             int l,r;
             cin>>l>>r;
             l--;
             r--;
             int f1 = 0, f2 = 0;
             if(s2[l] != sm2[l])
               f1 = 1;
             if(s2[r] != sm2[r])
               f2 = 1;
             int num = pre[r];
             if(l > 0) 
               num -= pre[l-1];
              if(sm1[l] != s1[l]){
                 num--;
              }
              if(sm1[r] != s1[r] && r != l){
                 num--;
              }
              if(r - l + 1 == 3 && (f1 || f2) && sm1[l+1] != s1[l+1]){
                  num--;
              }
              else if(r - l + 1 > 3){
                if( f1 && sm1[l+1] != s1[l+1]){
                    num--;
                }
                if(f2 && sm1[r-1] != s1[r-1]){
                    num--;
                }
              }
             cout<<num<<endl;
          }
      }
}