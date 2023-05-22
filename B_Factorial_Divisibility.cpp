#include<bits/stdc++.h>
using namespace std;

int main(){
   int a,x;
   cin>>a>>x;
  map<int,int>m;
   for(int i = 0;i<a;i++)
   {
    int num;
    cin>>num;
    m[num]++;
   }
   auto it = m.begin();
   auto itr = m.end();
   itr--;
   for(it = m.begin();it != itr;it++){
      int k = it->first;
      int l = it->second;
      if(l%(k+1) != 0){
        cout<<"No";
        return 0;
      }
      else{
        l = l/(k+1);
        m[k+1] = m[k+1] + l;
      }
   }
   int num = itr->second;
   int p = itr->first;
   while(num%(p+1) == 0){
    num = num/(p+1);
    p = p+1;
   }
   
   if(p>= x){
    cout<<"Yes";
   }
   else{
    cout<<"No";
   }
   return 0;
}