#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v[n+1];
    for(int i = 2;i<=n ;i++){
         int num;
         cin>>num;
         v[num].push_back(i);
    }
    int flag = 1;
    for(int i = 1;i<= n;i++){
          if(v[i].size() == 0){
            continue;
          }
          else{
            int count  = 0;
         for(auto value : v[i]){
               if(v[value].size() == 0){
                count++;
               }
         }
         if(count <= 2){
               flag = 0;
               break;
         }
          }
    }
    cout<< (flag ? "Yes" : "No");
}