#include<bits/stdc++.h>
using namespace std;

 
int main(){
  int a;
  cin>>a;
  while(a--){
    long long int a;
    cin>>a;
    vector<int>v;
    
    int count = 0;
    int flag = 0;
    for(int i = 2;i<= sqrt(a)+1;i++){
      if(count == 2){
        if( a%(v[0]*v[1]) == 0 ){
            if( a%(a/(v[0]*v[1])) == 0){
              int k = (a/(v[0]*v[1]));
              if(k !=  v[0] && k != v[1]){
                 flag = 1;
                 cout<<"YES\n"<<v[0]<<" "<<v[1]<<" "<<k<<"\n";
                 break;
              }
              else{
                v.erase(v.begin()+1);
                count--;
                continue;
              }
            }
             else{
                v.erase(v.begin()+1);
                count--;
                continue;
              }
        }
        else{
            v.erase(v.begin()+1);
                count--;
                continue;
        }
      }
      else{
        if(a%i == 0){
              v.push_back(i);
              count++; 
        }
      }
      
    }
    if(flag ==  0){
       cout<<"NO\n";
    }
    
  }
  return 0;
}