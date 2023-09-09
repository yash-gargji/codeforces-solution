#include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
     vector<int>p(n+1),s(n+1);
     vector<int>children[n+1];

     p[1] = -1;

     for(int i = 2;i <= n;i++){
        int num;
        cin>>num;
         p[i] = num;
        children[num].push_back(i);  
     }
     for(int i = 1;i <= n;i++){
           int num;
           cin>>num;
            s[i] = num;
     }
     int ans = 0;
    long long int sum = s[1];
     for(int i = 2;i<= n;i++){
             if(s[i] == -1){
                if(children[i].size() == 0 ){
                    s[i] = s[p[i]];
                     sum = sum + s[i] - s[p[i]];
                    continue;
                }
                 int m = 1e9 +1;
                for(int j = 0;j<children[i].size();j++){
                        m = min(m,s[children[i][j]]);
                }
                 if(m - s[p[i]] < 0){
                    ans = -1;
                    break;
                 }
                 else{
                   // s[i] = m - s[p[i]];
                   s[i] = m;
                       sum += s[i] - s[p[i]];
                 }
             }
             else{
                sum += s[i] - s[p[i]];
             }
     }
     if(ans == -1){
        cout<<ans;
        return 0;
     }
     cout<<sum;
}