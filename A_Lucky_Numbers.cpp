#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){

        int r,l;
        cin>>r>>l;
        int max = 0 ;
        int num;
        while(r<=l){
          string s1 = to_string(r);
          multiset<char>s;
          for(int i = 0;i<s1.size();i++){
              s.insert(s1[i]);
          }
           auto it = s.rbegin();
        it--; 
          auto itr = s.begin();
          int p = stoi((*it) - (*itr));
        } 
       
         
    }

}
