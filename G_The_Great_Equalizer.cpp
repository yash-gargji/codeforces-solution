#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;
        map<int,int>m,diff;
        int arr[n];
        vector<int>v(n);

        for(int i = 0;i<n;i++){
            cin>>arr[i];
            v[i] = arr[i];
        }
        sort(v.begin(),v.end());
        for(int i = 0;i<n;i++){
            m[v[i]]++;
            if(i != 0)
               diff[v[i] - v[i-1]]++;
        }
        int q;
        cin>>q;
        
        for(int i = 0;i<q;i++){
            int ind, val;
            cin>>ind>>val;
            m[arr[ind-1]]--;
            if(m[arr[ind-1]] == 0){
               auto it = m.find(arr[ind-1]);
               auto itr = it;
               if(it != m.begin()){
                  --itr;
                  int d = it->first - itr->first;
                  if(diff[d] == 1)
                    diff.erase(diff.find(d));
                  else 
                    diff[d]--;
                  ++itr;
               }
               ++itr;
                if(itr != m.end()){
                  int d = itr->first - it->first;
                  if(diff[d] == 1)
                     diff.erase(d);
                  else
                    diff[d]--;
                }
                auto it1 = it;
                ++it1;
                if(it1 != m.end() && it != m.begin()){
                    --it;
                    diff[it1->first - it->first]++;
                }
              m.erase(arr[ind - 1]);
            }  
            m[val]++;
            arr[ind - 1] = val;
            if(m[val] == 1){
               auto it = m.find(val);
               auto itr = it;
               if(it != m.begin()){
                  --itr;
                  int d = it->first - itr->first;
                  diff[d]++;
                  ++itr;
               }
               ++itr;
                if(itr != m.end()){
                  int d = itr->first - it->first;
                  diff[d]++;
                }
                auto it1 = it;
                it1++;
                if(it1 != m.end() && it != m.begin()){
                    --it;
                    if(diff[it1->first - it->first] == 1)
                       diff.erase(it1->first - it->first);
                    else
                     diff[it1->first - it->first]--;  
                }
            }
            if(m.size() > 1)
              cout<<m.rbegin()->first + diff.rbegin()->first<<" ";
            else 
              cout<<m.begin()->first<<" ";
        }
      cout<<endl;
    }
}