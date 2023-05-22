#include<bits/stdc++.h>
using  namespace std;

int main(){
      int n,m;
      cin>>n>>m;
      long long int arr[n];
      for(int i = 0;i<n;i++){
        cin>>arr[i];
      }
      long long int sum = 0;
        unordered_map<long long int,long long int>p;
      for(int i = 0;i<m;i++){
           int t;
           cin>>t;
           if(t == 3){
            int num;
            cin>>num;
            if(p.find(num-1) == p.end()){
            cout<<arr[num-1] + sum<<endl;
           }
           else{
            cout<<p[num-1]<<endl;
           }
           }
           else if(t == 1){
            long long int x,y;
            cin>>x>>y;
                p[x-1] = y;
           }
           else{
              long long int num;
              cin>>num;
                 sum = sum + num;
                 auto it = p.begin();
                 for(it = p.begin(); it != p.end();it++){
                       long int x = it->first;
                       p[x] = p[x] + num;
                 }
              }
           }
      return 0;
}
