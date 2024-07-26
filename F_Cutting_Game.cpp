#include<bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define ull unsigned long long
#define vi vector<int>
#define vll vector<long long>
#define vpi vector<pair<int,int>>
#define vpll vector<pair<ll,ll>>
 

void solve(){
    int a, b, n, m;
    cin>>a>>b>>n>>m;
    set<pair<int, int>> row, col;
    for(int i = 0; i < n; i++){
        int p, q;
        cin>>p>>q;
        row.insert({p, q});
        col.insert({q, p});
    }
    int u = 1, d = a, l = 1, r = b;
    int sum1 = 0, sum2 = 0;
    char c; int inp;
    for(int i = 0; i < m; i++){
        cin>>c>>inp;
        int cnt = 0;
        if(c == 'U'){
            if(!row.empty()){
                u = u + inp;
                vpi v;
                for(auto it = row.begin(); it != row.end(); it++){
                    if((*it).first >= u)break;
                    v.push_back({(*it).first, (*it).second});
                    cnt++;
                }
                for(auto j : v){
                    row.erase({j.first, j.second});
                    col.erase({j.second, j.first});
                }
            }
        }
        if(c == 'D'){
            if(!row.empty()){
                d = d - inp;
                vpi v;
                for(auto it = row.rbegin(); it != row.rend(); it++){
                    if((*it).first <= d)break;
                    v.push_back({(*it).first, (*it).second});
                    cnt++;
                }
                for(auto j : v){
                    row.erase({j.first, j.second});
                    col.erase({j.second, j.first});
                }
            }
            
        }
        if(c == 'L'){
            if(!col.empty()){
                l = l + inp;
                vpi v;
                for(auto it = col.begin(); it != col.end(); it++){
                    if((*it).first >= l)break;
                    v.push_back({(*it).first, (*it).second});
                    cnt++;
                }
                for(auto j : v){
                    col.erase({j.first, j.second});
                    row.erase({j.second, j.first});
                }
            }
        }
        if(c == 'R'){
            if(!col.empty()){
                r = r - inp;
                vpi v;
                for(auto it = col.rbegin(); it != col.rend(); it++){
                    if((*it).first <= r)break;
                    v.push_back({(*it).first, (*it).second});
                    cnt++;
                }
                for(auto j : v){
                    col.erase({j.first, j.second});
                    row.erase({j.second, j.first});
                }
            }
        }
        if(i % 2 == 0)
          sum1 += cnt;
        else 
          sum2 += cnt;
    }
    cout<<sum1<<" "<<sum2<<endl;
}

signed main(){
    
    int t;
    cin>>t;
    
    while(t--)
       solve();
    return 0;
}