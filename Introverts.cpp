#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<pair<int,int>>v(n);

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            v[i] = {num,i};
        }
        sort(v.begin(),v.end());
        if(n == 1){
             cout<<"YES\n";
             continue;
        }
        map<int,int>m;
        set<int>s;
        
        if((v[0].second != 0 && v[0].second != n-1) || (v[1].second != 0 && v[1].second != n-1)){
           cout<<"NO\n";
           continue;
        }
        int flag = 1;
        s.insert(0);
        s.insert(n-1);
        m[n-2]++;

        for(int i =2 ;i<n;i++){
            int ind = v[i].second;
            auto it = s.upper_bound(ind);
            int u = *it;
            --it;
            int l = *it;
            int dis = min(ind - l - 1,u - ind - 1);
            auto itr =prev(m.end());
            int f = 0;
            if(itr->first % 2){
                 f = itr->first/2;
            }
            else{
               f = itr->first/2;
               f--;
            }
            if(dis < f){
                 flag = 0;
                 break;
            }
            s.insert(ind);
            if(m[u - l - 1] == 1){
                m.erase(m.find(u-l-1));
            }
            else{
                m[u - l - 1] --;
            }
            m[ind - l - 1]++;
            m[u - ind - 1]++;
        }
       if(flag)
         cout<<"YES\n";
        else 
          cout<<"NO\n";
    }
}