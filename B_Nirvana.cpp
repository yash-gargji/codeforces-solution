#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    s = to_string(n);
    if(s.size() == 1){
        cout<<s;
      return 0;
    }
    int prod = 1;
    int ans = 1;

    for(int i = 0;i<s.size();i++){
           if(s[i] == '0'){
            break;
           }
           else if(s[i] == '1' && i == 0){
                int num = pow(9,s.size() - 1 - i);
              ans = max(ans,num);
           }
           else if(s[i] == '1'){
                    continue;
           }
           else{
                 int num = pow(9,s.size() - 1 - i);
                 num = num*(s[i]-48-1)*prod;
                  ans = max(ans,num);
                  prod = prod*(s[i]-48);
           }
    }
     ans = max(ans,prod);
    cout<<ans;
}