#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin>>n>>k;
   vector<int>v[n+1],c(n+1),p(n+1);
   for(int i = 1;i<= n;i++){
    int num;
    cin>>num;
       c[i] = num;
   }
   p[1] = -1;
   for(int i = 0;i<n-1;i++){
    int num1,num2;
    cin>>num1>>num2;
    v[num1].push_back(num2);
    p[num2] = num1;
   }
   int count = 0;
   for(int i = 1;i<= n;i++){
   
       if(v[i].size() == 0){
        int son = i;
              int num = 0 ;
              int flag = 0;
              while(son != -1){
                if(c[son] == 0){
                    num = 0;
                }
                  num += c[son];
                 son = p[son];
                 if(num == k+1){
                     flag = 1;
                     break;
                 }
              }
              count += !flag;
       }
   }
   cout<<count;
}