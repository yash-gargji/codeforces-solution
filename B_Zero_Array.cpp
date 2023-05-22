#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
      multiset<int>s;

      for(int i = 0;i<a;i++){
        int n;
        cin>>n;
        s.insert(n);
      }
      while(s.size() > 1){
           auto itr  = s.begin();
           int x = (*itr);
           auto it  = s.end();
           it--;
           int y = (*it);
           y = y-x;
           s.erase(it);
            s.erase(itr);
            if(y == 0){
                continue;
            }
            else{
                s.insert(y);
            }
      }
      if(s.size() == 0){
        cout<<"YES\n";
      }
      else{
        cout<<"NO\n";
      }
      return 0;
}