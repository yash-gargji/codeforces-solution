#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num = n+1;
    int k = n;
    for(int i = 1;i<=n +1;i++){
       
         for(int j = 1;j<= abs(num - i);j++){
            cout<<"  ";
         }
         
      for(int j = 0;j<= i-1;j++){
        cout<<j;
        if(i != 1){
            cout<<" ";
        }
      }
      for(int j = i-2;j>= 0 ;j--){
        cout<<j;
        if( j!= 0){
            cout<<" ";
        }
      }
        
         cout<<endl;
    }
    for(int i = n+2;i<=2*n+1;i++){
        for(int j = 1;j<= abs(num - i);j++){
            cout<<"  ";
         }
          for(int j = 0;j<= k-1;j++){
            cout<<j;
             if(k != 1){
            cout<<" ";
        }
      }
        for(int j = k-2;j>= 0 ;j--){
        cout<<j;
        if(j != 0){
            cout<<" ";
        }
      }
         k--;
         cout<<endl;
    }
    return 0;
}
