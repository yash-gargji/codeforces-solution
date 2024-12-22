#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];

        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        int ans = 0;
        stack<pair<int,int>>st;
        
        for(int i = 0;i<n;i++){
            int num = 0;
            while(!st.empty() && arr[st.top().first] < arr[i]){
                num = st.top().second + i - st.top().first; 
                st.pop();
            }
            st.push({i,num});
            ans = max(ans,num);
        }
      cout<<ans<<endl;
    }
}