#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
      int n;
      cin>>n;
        if(n != 1 && n%2 == 1){
            cout<<"-1\n";
            continue;
        }
        int count = 0;
        cout<<n<<" ";
        int x = n-1;
        int y = 2;
        for(int i = 2;i<=n;i++){
              if(i%2 == 0){
                cout<<x<<" ";
                x = x-2;
              }
              else{
                cout<<y<<" ";
                y= y+2;
              }
        }
        cout<<endl;
    }
    return 0;
}