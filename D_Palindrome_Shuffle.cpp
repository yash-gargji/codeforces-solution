#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        string s;
        cin>>s;
        int n = s.size();

        vector<vector<int>>v(n,vector<int>(26));
        vector<int>ind;
        
        for(int i = 0;i<n;i++){
            if(i != 0)
              v[i] = v[i-1];
            v[i][s[i] - 'a']++;
            if(i < n/2 && s[i] != s[n - i -1]){
                ind.push_back(i);
                ind.push_back(n-i-1);
            }
        }
        if(ind.size() == 0){
            cout<<0<<endl;
            continue;
        }
        sort(ind.begin(),ind.end());
        int ans = INT_MAX;
        int l = ind[0];
        int r = ind[ind.size()/2-1];
        int flag = 0;
        
        for(int i = 0;i<26;i++){
            int x = v[r][i];
            if(l != 0)
              x -= v[l-1][i];
            int y = v[ind[ind.size() - 1]][i];
              y -= v[ind[ind.size()/2] -1][i];
              if(x != y)
                flag = 1;
          
        }
        if(flag == 0){
            cout<<r - l + 1<<endl;
            continue;
        } 
        r = ind[ind.size()-1];
        int mid = n / 2;
        for(int i = mid;i<r;i++){
            vector<int>vec = v[i];
            int count = 0;
            if(l != 0){
                for(int j = 0;j<26;j++){
                    vec[j] = vec[j] - v[l-1][j];
                }
            } 
            for(int j = 0;j<26;j++){
                vec[j] = vec[j] - (v[r][j] - v[i][j]);
                if(vec[j] < 0){
                    count = INT_MAX;
                    break;
                }
                count += vec[j]% 2;
            }
            if(count <= 1){
               ans = min(ans ,i - l + 1);
            }
        }
        for(int i = l+1;i< mid;i++){
            vector<int>vec = v[r];
            int count = 0;
            
            for(int j = 0;j<26;j++){
                vec[j] = vec[j] - v[i-1][j];
            }
            for(int j = 0;j<26;j++){
                vec[j] = vec[j] - (v[i-1][j] - (l > 0 ? v[l-1][j] : 0 ));
                if(vec[j] < 0){
                    count = INT_MAX;
                    break;
                }
                count += (vec[j] + 1000000 ) % 2;
            }
            if(count <= 1){
               ans = min(ans ,r - i + 1);
            }
        }
        cout<<ans<<endl;
    }
}