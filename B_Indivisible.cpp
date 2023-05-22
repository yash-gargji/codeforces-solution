#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int n;
        cin>>n;
        if(n == 1){
          cout<<"1\n";
          continue;
        }
          if((n*(n+1)/2)%n == 0 && n != 1){
            cout<<-1<<endl;
          }
          else{
            for(int i = 1;i<n;i = i+2){
              cout<<i+1<<" "<<i<<" ";
            }
           cout<<endl;
    }
    }
    return 0;
}