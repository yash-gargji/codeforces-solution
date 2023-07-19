#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
             ll n,k;
             cin>>n>>k;
              pair<ll,pair<ll,ll>>p[n];
              for(int i  = 0;i<n;i++){
                    int num1;
                    cin>>num1;
                    p[i].second.first = num1;
              }
               for(int i  = 0;i<n;i++){
                    int num2;
                      cin>>num2;
                      int num1 =  p[i].second.first;
                      p[i] = {num2/num1,{num1,num2}};
              }
              if(n == 1){
                cout<<(k+p[0].second.second)/p[0].second.first;
                return 0;
              }
        sort(p,p+n);
        int count = 0;
           ll main = 0;
           ll mod = 0;
           ll sub = 0;
          for(int i = 0;i<n;i++){
             
              main = main + p[i].second.first;
              sub = sub + p[i].second.first;
              mod = mod + (p[i].second.second) % (p[i].second.first);
                   int flag = -1;
              for(int j = i+1;j<n;j++){
                   if(p[j].first != p[i].first){
                    flag = p[j].first;
                    break;
                   }
                   else{
                    i = j;
                  
                    sub = sub + p[j].second.first;
                     main = main + p[j].second.first;
                    mod = mod + p[j].second.second % p[j].second.first;
                   }
              }
                if(k <= 0){
                break;
              }
              if(flag == -1){
                count = p[i].first;
                if(main - mod > k){
                    break;
                }
                else{
                       count++;
                       k = k - main + mod;
                }
                count = count + k/main;
                k = 0;
              }
              else{
                  ll req = (flag - p[i].first)*main - mod;
                  if(k >= req){
                    k = k - req;
                    count = flag;
                  }  
                  else{
                      if(main - mod > k){
                    break;
                }
                      else{
                       count++;
                       k = k - main + mod;
                   }
                   count = count + k/main;
                    k = 0;
                  }
              }
               sub = 0;
               mod = 0;
       }
         cout<<count<<endl;
}