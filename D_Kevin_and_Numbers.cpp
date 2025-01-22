#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,m;
       cin>>n>>m;
       
       map<int,long long>m1,m2;

       for(int i = 0;i<n;i++){
           int num;
           cin>>num;
            m1[num]++;
       }
       for(int i = 0;i<m;i++){
           int num;
           cin>>num;
           m2[num]++;
       }
       for(auto &it:m2){
           int num = min(m1[it.first],m2[it.first]);
           m2[it.first] -= num;
           m1[it.first] -= num;
       }
       while(m2.size() > 0 ){
           auto it = m2.end();
           it--;
           if(it->first == 0)
             break;
           long long num = min(it->second,m1[it->first]);
           m1[it->first] -= num;
           int a = it->first/2;
           int b = a + it->first%2;
           if(num < it->second){
              m2[a] += (it->second - num);
              m2[b] += (it->second - num);
           }
        //    cout<<a<<" "<<b<<" "<<num<<endl;
           m2.erase(it->first);
       }
       int flag = 1;

       for(auto it:m1){
          if(it.second > 0) 
            flag = 0;
       }
       if(m2.size() == 0 && flag){
         cout<<"Yes\n";
       }
       else{
         cout<<"No\n";
       }
    }
}