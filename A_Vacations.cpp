#include<bits/stdc++.h>
using namespace std;

int main(){
    long int a;
    cin>>a;
      vector<int>v;
    int count  = 0;
    for(int i = 0;i<a;i++){
         int num;
         cin>>num;
         if(num == 0){
          count++;
         }
          v.push_back(num);
    }
    int key = 0;
    int flag = 0;
    for(int i = 0;i<v.size();i++){
      if(v[i] == 0){
        flag = 0;
      }
         else if(flag == 0){
            if(v[i] == 1){
              key = 1;
              flag = 1;
            }
            else if(v[i] == 2)
            {
              key = 2;
              flag = 1;
            }
            else{
              int r = i+1;
              int  c2 = 0;
              for(int j = i;j<v.size();j++){
                   r = j+1;
                   if(v[j] != 3){
                       break;
                   }
                   else{
                    c2++;
                   }
              }
              if(r = v.size()){
                break;
              }
              else if(c2%2 == 0){
                     key = v[r];
                     flag = 1;
              }
              else{
                key = 3 - v[r];
              }
            }
           }
           else{
              if(key == v[i] && flag == 1){
                count++;
                flag = 1;
              }
              else{
                key = 3 - key;
              }
           }
    }
  cout<<count;
}