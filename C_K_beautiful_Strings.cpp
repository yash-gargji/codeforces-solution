#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        if(n % k){
            cout<<"-1\n";
            continue;
        }
        vector<vector<int>>v(n,vector<int>(26));
        v[0][s[0] - 'a']++;

        for(int i = 1;i<n;i++){
           v[i][s[i] - 'a']++;
           for(int j = 0;j<26;j++){
             v[i][j] += v[i-1][j];
           }
        }
        int count = 0;
        for(int i = 0;i<26;i++){
             count += v[n-1][i] % k;
        }
        if(!count){
            cout<<s<<endl;
            continue;
        }
        for(int i = n-1;i >= 0;i--){
            int req = 0;
            v[i][s[i] - 'a']--;
            int flag = 0;
            for(int j = 0;j<26;j++){
               if(v[i][j] % k != 0){
                  req += k - v[i][j] % k;
               }
            }
            if(req > n - i)
              continue;
            for(int j = s[i] - 'a' + 1;j<26;j++){
                 int num = req;
                if(v[i][j] % k == 0){
                   num += k - 1;
                }
                else{
                    num--;
                }
                if(num > n - i-1)
                 continue;
                if((n - i - 1 - num) % k == 0){
                    s[i] = 'a' + j;
                   flag = 1;
                   v[i][j]++;
                   req = num;
                   break;
                }
            }
            if(flag){
                 int ind = i+1;
                for(int j = i+1;j<n - req;j++){
                    s[ind++] = 'a';
                }
                for(int j = 0;j<26;j++){
                    int num = 0;
                    if(v[i][j] % k){
                        num = k - v[i][j] % k;
                    }
                    while(num--){
                        s[ind++] = 'a' + j;
                    }
                }
              cout<<s<<endl;
              break;
            }
        }
    }
}