#include<bits/stdc++.h>
using namespace std;

int main(){
     int a;
     cin>>a;
     while(a--){
        int x;
        cin>>x;
        if(x == 2){
            cout<<-1<<endl;
            continue;
        }
        else if(x == 1){
            cout<<"1\n";
            continue;
        }
        int even = 0;
        int odd = 1;
        for(int i = 0;i<x;i++){
            for(int j = 0;j<x;j++){
                if(i == 0 && j == 0){
                    cout<<"1 ";
                }
              else{  odd = odd+2;
                if(odd > x*x){
                    even = even +2;
                    cout<<even<<" ";
                }
                else{
                    cout<<odd<<" ";
                }
            }
            }
            cout<<endl;
        }
     }
}