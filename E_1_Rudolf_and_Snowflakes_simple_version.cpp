 #include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
          int t;
          cin>>t;
          while(t--){
              long long int n;
              cin>>n;
              if( n <= 4){
                cout<<"NO\n";
                continue;
              }
              int flag = 0;
              for(int i = 2;i<=sqrt(n);i++){
                    long long int num1 = 1;
                    long long int sum = 1;
                    while(sum < n){
                      num1 = num1 *i;
                      sum = sum + num1;
                    }
                    if(sum == n){
                      flag = 1;
                      break;
                    }
              }
              if(flag){
                cout<<"YES\n";
              }
              else{
                cout<<"NO\n";
              }
          }
}