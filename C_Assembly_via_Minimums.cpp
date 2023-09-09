#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
      int t;
      cin>>t;
      
      while(t--){
          int n;
          cin>>n;
          
        map<int,int>m;
        vector<int>v;
        
    int num = (n*(n-1))/2;

    for(int i = 0;i < num ;i++){
           int k;
           cin>>k;
           m[k]++;
    }
    
    int i = n-1;
    for( auto it = m.begin() ; it!= m.end() ;it++){

        while(it->second != 0){
            v.push_back(it->first);
               it->second -= i;
            i--;
        }
    }

    v.push_back(1e9);

    for(int i=0;i<n;i++){
        cout<<v[i]<<" ";  
      }

      cout<<endl;
}
}