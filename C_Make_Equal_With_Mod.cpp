#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int a;
    cin>>a;
    while(a--){
        int x;
        cin>>x;
        
          set<int>s;
          int one = 0 ;
          int zero = 0;
          int two = 0;
          int arr[x];
          for(int i  =0;i<x;i++){
            ll num;
            cin>>num;
            arr[i] = num;
            if(num == 1){
                one = 1;
            }
             if(num == 2){
                two = 1;
            } 
            if(num == 0){
              zero = 1;
            }
            s.insert(num);
          }
        
          if(s.size() == 1){
            cout<<"YES\n";
            continue;
          }
          else if( zero == 1 && one == 1) {
               cout<<"NO\n";
                 continue;
             }
          else if(one == 0){
              cout<<"YES\n";
                continue;
           }
          else{
             sort(arr,arr+x);
            int flag = 1;
            for( int i = x-1; i>0;i--){
                  ll a,b;
                  a = arr[i];
                  b = arr[i-1];
                  if(a-1 == b){
                      flag = 0;
                      cout<<"NO\n";
                      break;
                  }
            }
            if(flag == 1){
                  cout<<"YES\n";
                 continue;
            }
          }

    }
    return 0;
}