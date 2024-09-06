#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
         int l,r;
        cin>>l>>r;
         int num =0;
        int  i=1;
        while(l<=r){
            l+=i;
            i++;
            num++;
        }
        cout<<num<<endl;
    }
}