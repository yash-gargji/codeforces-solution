#include<bits/stdc++.h>
using namespace std;

void func(long long low,long long high,vector<long long>&ans){
     if(low == high){
        ans.push_back(low);
        return ;
     }
     if(ans.size() == 3)
        return ;
     long long mid = low + (high - low)/2;
     cout<<"xor "<<low<<" "<<mid<<endl;
     long long r;
     cin>>r;
     if(r != 0)
       func(low,mid,ans);
      if(ans.size() == 3 )
        return ;
     cout<<"xor "<<mid + 1<<" "<<high<<endl;
     cin>>r;
     if(r != 0)
       func(mid + 1,high,ans);
}

int main(){
   int t;
   cin>>t;

   while(t--){
      vector<long long>ans;
      long long int n;
      cin>>n;
      long long num = 1;
      int ind = 1;
      cout<<"xor "<<1<<" "<<n<<endl;
      long long p;
      cin>>p;
      if(p == 0){
         while(ind <= 62 ){
            num = 1ll << ind++;
            cout<<"xor "<<1<<" "<<min(n,num-1)<<endl;
            long long r;
            cin>>r;
            if(r != 0){
               if(num - 1 != 1)
               func(1,min(num-1,n),ans);
               else
               ans.push_back(1);
               if(num <= n)
               func(num,n,ans);
               break;
            }
         }
      }
      else{
         func(1,n,ans);
      }
       sort(ans.begin(),ans.end());
       cout<<"ans "<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;
   }
}