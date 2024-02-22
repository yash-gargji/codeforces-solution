#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         string s;
         int m = 0;
         int n = 0;

         cin>>s;

         for(int i = 0; i<s.size();i++){
            if(s[i] == 'A') {
                m++;

            }
            else {
                n++;
            }
         }
         if(m > n) cout<<"A\n";
         else cout<<"B\n";
        
    }
}