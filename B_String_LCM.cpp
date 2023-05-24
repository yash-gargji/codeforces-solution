#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin>>a>>b;
           int x = a.size();
           int y = b.size();
           int lcm =  (x*y)/(__gcd(x,y));
           string o = a,p = b;
            for(int i = 0;i<lcm/x - 1;i++){
                a = a+ o;
            }
            for(int i = 0;i<lcm/y - 1;i++){
               b = b + p;
            }
            if(a == b){
                cout<<a<<endl;
        }
        else{
            cout<<"-1\n";
        }
    }
    return 0;
}