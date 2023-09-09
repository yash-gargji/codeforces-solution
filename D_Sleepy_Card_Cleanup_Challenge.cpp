  #include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
          vector<int>v(1e5 + 1);
          int ans = 0;
             
             int count = 0;
             int check = 1;
         for(int i = 0;i<n;i++){
                 int num;
                 cin>>num;
                v[num]++;
                 if(num >= check ){
                   count ++;
                 }
                 if(count >= check){
                     ans = check;
                     cout<<ans<<" ";
                     count = count - v[ans];
                     check++;
                 }
                 else{
                     cout<<ans<<" ";
                 }
              }
               cout<<endl;
         }
          
    }
