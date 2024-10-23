#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
        int num = -1;
        
        for(int i = 0;i<min(a.size(),b.size());i++){
             if(a[i] == b[i]){
                num++;
             }
             else 
               break;
        }
      cout<<a.size() + b.size() - max(num,0)<<endl;
    }
} 