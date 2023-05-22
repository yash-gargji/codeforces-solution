#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
   pair<long long int,long long int >p[a];
   for(int i = 0;i<a;i++){
    cin>>p[i].first>>p[i].second;
   }
   int count = 0 ;
   for(int i = 0;i<a;i++){
       if(i == 0  || i == a-1){
        count++;
        continue;
       }
       int x = p[i].first;
       int y = p[i].second;
       if(x - y > p[i-1].first){
        count ++;
       }
       else if(x + y < p[i+1].first){
        count ++;
        p[i].first = p[i].first + y;
       }
   }
   cout<<count;
   return 0;
}