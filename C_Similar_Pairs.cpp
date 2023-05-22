#include<bits/stdc++.h>
using namespace std;

int main(){
  int t;
  cin>>t;
  while(t--){
    int a;
    cin>>a;
    int odd = 0;
    int even = 0;
    multiset<int>s;
      for(int i = 0;i<a;i++){
        int num;
        cin>>num;
        s.insert(num);
        if(num%2 == 0){
             even++;
        }
        else{
            odd++;
        }
      }
    if(odd%2 == 0 && even%2 == 0){
            cout<<"YES\n";
    }
    else{
        auto it = s.begin();
        int flag = 0;
        for(it = s.begin(); it != s.end();it++){
               int num = (*it);
               if(num%2 == 1){
                    auto itr = s.find(num-1);
                    if(itr != s.end()){
                        flag = 1;
                        break;
                    }
                     auto ir = s.find(num+1);
                      if(ir != s.end()){
                         flag = 1;
                        break;
                    }
               }
        }
        if(flag == 1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
  }
  return 0;
}