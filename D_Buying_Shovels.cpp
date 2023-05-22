#include<bits/stdc++.h>
using namespace std;
 
 
int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   int a;
   cin>>a;
   while(a--){
    long long int x,y;
    cin>>x>>y;
    if(x%y == 0){
        cout<<x/y<<endl;
    }
     else if(x<y){
        cout<<1<<endl;
    }
     
    else{
       long long int  m = x;

        for(long long int i = 1;i*i<=x;i++){
            if(x%i == 0){
                if(i <= y ){
                 m = min(m,x/i);
                }
                if(x/i <= y){
               m = min(m,i);
                }
            }
        }
        cout<<m<<endl;
          }
    }
return 0;
}