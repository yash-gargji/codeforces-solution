#include<bits/stdc++.h>
using namespace std;

int main(){
      int n;
      cin>>n;
      map<int,int>m;
      map<int,vector<int>>ind;

      for(int i = 0;i<n;i++){
          int num;
          cin>>num;
          ind[num].push_back(i+1);
          m[num]  = 1 + m[num-1];
      }
      int ans = 0;
      int num;
      for(auto it:m){
        if(it.second >= ans){
            ans = it.second;
            num = it.first;
        }
      }
      int ub = n+1;
      stack<int>st;
      
      while(ans--){
          int l  = 0;
          int h = ind[num].size() - 1;
          int k = -1;
          while(l <= h){
             int mid = (l + h)/2;
               if(ind[num][mid] < ub){
                  k = mid;
                  l = mid + 1;
               }
               else
                 h = mid-1;
          }
          if(k != -1)
            st.push(ind[num][k]);
          ub = ind[num][k];
          num--;
      }
      cout<<st.size()<<endl;

      while(!st.empty()){
          cout<<st.top()<<" ";
          st.pop();
      }
}