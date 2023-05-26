#include<bits/stdc++.h> 
 using namespace std;

 int main(){
      int n;
      cin>>n;
      string s;
      cin>>s;

      vector<int>v;
      for(int i = 0;i<n;i++){
           int num;
           num =  s[i] - 48;
           if(num == 1 || num == 0){
               continue;
           }
           else if(num == 4){
            v.push_back(2);
             v.push_back(2);
              v.push_back(3);
           }
           else if(num == 8){
            v.push_back(2);
             v.push_back(2);
              v.push_back(2);
              v.push_back(7);
           }
           else if(num == 6){
               v.push_back(3);
             v.push_back(5);
             
           }
           else if(num == 9){
             v.push_back(3);
             v.push_back(3);
              v.push_back(2);
              v.push_back(7);
           }
           else{
            v.push_back(num);
           }
      }
      sort(v.begin(),v.end());
      for(int i = v.size()-1;i>=0;i--){
        cout<<v[i];
      }
      return 0;
 }
