#include<bits/stdc++.h>
using namespace std;


int main(){
    int a;
    cin>>a;

    while(a--){
        long int x,y,z;
        cin>>x>>y>>z;
        int count  = 0;
         if(x == 0 || y == 0)
         {
            cout<<0<<endl;
            continue;
         } 
         else if(z>y || z>x){
            cout<<min(x,y)<<endl;
            continue;
         }
        count  = count +z;
        x = x- z;
        y = y-z;
        if(x>=y){
            if(x>= 2*y){
                cout<<y + count<<endl;
            }
            else {
                cout<<(x+y)/3 + count<<endl;
            }
        }
        else{
             if(y>= 2*x){
                cout<<x + count<<endl;
            }
            else {
                cout<<(x+y)/3 + count<<endl;
            }
        }
    }
}