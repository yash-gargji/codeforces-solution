#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
           int n;
            cin>>n;
           vector<int>a(n),b(n);
            for(int i=0;i<n;i++)
              cin>>a[i];
            for(int i=0;i<n;i++)
              cin>>b[i];
            int flag = 1;
            for(int i=0;i<n;i++){
                if(a[i]!=b[i]){
                    flag=0;
                }
            }
            if(flag == 1){
                cout<<"Bob"<<endl; 
                continue;
            }
            flag=1;
            for(int i=0;i<n;i++){
                if(a[i] != b[n-i-1]){
                    flag=0;
                }
            }
            if(flag == 0 ){
                cout<<"Alice"<<endl;
            }
            else cout<<"Bob"<<endl;   
     }
}