#include<bits/stdc++.h>
using namespace std;

int pow(int n,int k){
    int num = 1;

    for(int  i = 0;i<k;i++){
        num *= n;
        if(num > 1e6) return num;
    }
    return num;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int a,b,l;
         cin>>a>>b>>l;
          unordered_set<int>s;
      
         for(int i = 0;i<= 31;i++){
            for(int j = 0;j<=31;j++){
                int k = pow(a,i);
                int p = pow(b,j);
                int num = k*p;
                 if(num > l) break;
                    // cout<<num<<" ";
                 if(l % num == 0) {
                     s.insert(l/num);

                    //  cout<<l/num<<" ";
                 }
            }
         }
         cout<<s.size()<<endl;
    }
}