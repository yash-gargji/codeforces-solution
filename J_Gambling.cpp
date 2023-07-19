#include<bits/stdc++.h>
using namespace std;

int main(){
     
          int n;
          cin>>n;
          vector<int>ev,od;
          for(int i = 0;i<n;i++){
            int num;
            cin>>num;
           ev.push_back(num);
          }
         for(int i = 0;i<n;i++){
            int num;
            cin>>num;
           od.push_back(num);
          }
          long long int s1 = 0 , s2 = 0;
          int x = od.size()- 1;
          int y = ev.size() - 1;
          sort(ev.begin(),ev.end());
           sort(od.begin(),od.end());
          for(int i = 0;i<2*n;i++){
               if(i%2 == 0){
                  if(y == -1 ){
                    x--;
                  }
                  else if(x == -1){
                    s1 += ev[y];
                    y--;
                  }
                  else if(ev[y] < od[x]){
                    x--;
                  }
                  else{
                      s1 += ev[y];
                    y--;
                  }
               }
               else{
                    if(x == -1 ){
                        y--;
                  }
                   else if(y == -1){
                    s2 += od[x];
                    x--;
                  }
                  else if(ev[y] > od[x]){
                    y--;
                  }
                  else {
                    s2 += od[x];
                    x--;
                  }
               }
          }
         cout<<s1-s2;
    }
