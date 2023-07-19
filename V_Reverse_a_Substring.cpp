#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
     string s;
     cin>>s;
     string b = s;
     reverse(s.begin(),s.end());
     stack<int>st;
     int f,r;
         int flag = 0;
         for(int i = 0;i<s.size();i++){
            while( !st.empty() && s[i] > s[st.top()]){
                    r = i;
                    f = st.top();
                    flag = 1;
                    break;
            }
            if(flag){
                break;
            }
            st.push(i);
         }
          if(flag == 0){
            cout<<"NO";
          }
          else{
            cout<<"YES\n";
            cout<<s.size()-r<<" "<<s.size()-f;
          }
}