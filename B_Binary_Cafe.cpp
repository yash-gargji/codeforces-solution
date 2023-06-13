 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     int t;
     cin>>t;
     
     while(t--){
          long long int n,m;
             cin>>n>>m;
             if(m>32)cout<<1+n<<endl;
            //    if((int)pow(2,m) - 1 <= n){
            //     cout<<(int)pow(2,m)<<endl;
            //    }
               else if((int)pow(2,m) - 1 > n){
                cout<<n+1<<endl;
               }
               else cout<<(int)pow(2,m)<<endl;
     
     }
     
    return 0;
 }