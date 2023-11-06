  #include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int t;
     cin>>t;
    
    while(t--){
         int n,x;
         cin>>n>>x;
          int odd = 0;
          int even = 0;

          for(int i = 0;i<n;i++){
            int num;
            cin>>num;
                if(num%2 == 0){
                    even ++;
                }
                else{
                    odd++;
                }
          }
            if(x%2 == 0 && even == 0){
                cout<<"No\n";
            }
            else if(x%2 == 0 && odd == 0){
                   cout<<"No\n";
            }
            else if(x%2 == 1 && odd == 0){
                cout<<"No\n";
            }
            else if(x == n && odd%2 == 0){       
                cout<<"No\n";
            }
            else{
                cout<<"Yes\n";
            }
    }
}