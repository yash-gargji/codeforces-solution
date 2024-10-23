#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        int ma = INT_MIN;
        int mi = INT_MAX;
        int f = 1;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
           if(num != i+1){
              f = 0;
             ma = max(num,ma);
             mi = min(mi,num);
           }
        }
        if(f){
             cout<<"0\n";
        }
        else{
           cout<<ma+1<<endl;
        }
    }
}