#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int i = 1;
        int j = 2;
        int k = 3;
        int res =  1;
        int turn = 0;

        while(res){
           cout<<"? "<<i<<" "<<j<<" "<<k<<endl;
           cin>>res;
           if(res == 0)
              break;
            if(turn == 0)
              i = res;
            else 
              k = res;
            turn = !turn;
        }
        cout<<"! "<<i<<" "<<j<<" "<<k<<endl;
    }
}