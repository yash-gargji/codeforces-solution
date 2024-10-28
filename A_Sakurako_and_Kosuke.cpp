#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int num = 0;
        int f = 0;
        
        int c = 1;
        while(abs(num) <= n){
            if(!f)
              num = num - (2*c - 1);
            else 
             num += 2*c - 1;
            c++;
            f = !f;
        }
       if(f == 1)
         cout<<"Sakurako\n";
        else 
          cout<<"Kosuke\n";
    }
}