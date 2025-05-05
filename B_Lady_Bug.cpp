#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
        int n ;
        cin>>n;
        string a,b;
        cin>>a>>b;
        

        int o = 0,z = 0;

        for(int i = 0;i<a.size();i++){
            if(i % 2 == 0 && a[i] == '0'){
               z++;
            }
            else if(i % 2 == 1 && b[i] == '0')
              z++;
        }
        for(int i = 0;i<a.size();i++){
            if(i % 2 == 1 && a[i] == '0'){
               o++;
            }
            else if(i % 2 == 0 && b[i] == '0')
              o++;
        }
        
        if(z >= n/2 + n%2 && o >= n/2){
            cout<<"YES\n";
        }
        else{
              cout<<"NO\n";
        }
     }
}