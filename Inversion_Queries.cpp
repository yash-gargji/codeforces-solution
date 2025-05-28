#include<bits/stdc++.h>
using namespace std;
#define int long long

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        int q;
        cin>>q;

        int arr[n];
        ordered_set st;

        vector<int>pre(n+1),suff(n+1);

        for(int i = 0;i<n;i++){ 
            cin>>arr[i];
            suff[arr[i]] = i - st.order_of_key(arr[i]);
            st.insert(arr[i]);
        }
        ordered_set st1;
        for(int i = n-1;i >= 0;i--){ 
            cin>>arr[i];
            pre[arr[i]] = st1.order_of_key(arr[i]);
            st1.insert(arr[i]);
        }
        for(int i = 1;i<= n;i++){
            pre[i] += pre[i-1];
        }
        for(int i = n-1;i > 0;i--){
            suff[i] += suff[i+1];
        }
        int ans = pre[n];

        while(q--){
            int l,r;
            cin>>l>>r;
            if(l == r){
               cout<<0<<endl;
               continue;
            }
            cout<<ans - pre[l] - suff[r]<<endl;
        }
    }
}