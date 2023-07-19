#include<bits/stdc++.h>
using namespace std;

int main(){
      int t;
      cin>>t;
      while(t--){
        int l;
        cin>>l;
        vector<int>v;
        int p = 0,n = 0,z = 0;
        for(int i = 0;i<l;i++){
              int num;
              cin>>num;
              if(num>0){
                p++;
                v.push_back(num);
              }
              else if(num == 0){
                z++;
              }
              else{
                   n++;
                v.push_back(num);
              }
        }
        if(p >=3 || n >= 3){
            cout<<"NO\n";
            continue;
        }
        if(z != 0)
        {
            v.push_back(0);
        }
        int flag = 0;
        
        for(int i = 0;i<v.size();i++){
           long long int sum = v[i];
            
            for(int j = 0;j<v.size();j++){
                if(j == i){
                    continue;
                }
                sum += v[j];
                
                 for(int k = 0;k<v.size();k++){
                    if(k == j || k == i){
                        continue;
                    }
                    sum += v[k];
                    
                    auto it = std::find(v.begin(),v.end(),sum);
                          if( it == v.end()){
                            
                            flag = 1;
                            break;
                          }
                          sum = sum - v[k];
                 }
                 if(flag){
                    break;
                  }
                  sum = sum- v[j];
            }
                if(flag){
                    break;
                  }
        }
        if(flag){
            cout<<"NO\n";
        }
        else{
             cout<<"YES\n";
        }
      }
}