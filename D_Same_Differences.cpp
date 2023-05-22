#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
       long int a;
        cin>>a;

        map<long long int,long long int>m;
      unsigned long long int count = 0;
        for(long int i = 0;i<a;i++){
           long long int num;
            cin>>num;
             m[num - (i+1)]++;
        }
       for(auto it = m.begin(); it != m.end();++it){
          long long  int y = it->second;
          unsigned long long int sum = (y*(y-1))/2;
           count = count + sum;
       }
       cout<<count<<endl;
    }
    return 0;
}