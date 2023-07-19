#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
          int n;
          cin>>n;
          vector<string>v(n);
          for(int i = 0;i<n;i++){
            cin>>v[i];
          }
          int flag = 0;
          for(int i = 0;i<n;i++){
               string s = v[i];
               string num;
               for(int j = 0;j<s.size()-1;j++){
                       num = num + s[j];
                      auto it = std::find(v.begin(),v.end(),num);
                      if(it != v.end()){
                        string p;
                        for(int k = j+1;k<s.size();k++ ){
                             p = p +  s[k];
                        }
                        auto itr = std::find(v.begin(),v.end(),p);
                        if(itr != v.end()){
                            flag = 1;
                            break;
                        }
                      }
               }
               cout<<flag;
               flag = 0;
          }
          cout<<endl;
    }
}