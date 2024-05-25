#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
    cin>>t;

    while(t--){
        long long int a,b,k;
        cin>>a>>b>>k;

       int count = 0;

       while(a != b){ 
            if(b%k == 0){
                if(b/k < a){
                     count += b -a;
                     b = a;
                } 
                else 
                 {
                     b = b/k;
                     count++;
                 }
            }
            else {
               int num = min(b%k,b - a);
               count += num;
               b = b - num;
            }
       }
      cout<<count<<endl;
    }
}
