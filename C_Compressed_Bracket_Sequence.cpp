#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int arr[n];
     long long ans = 0, count = 0;
     stack<pair<long long ,long long>>st;
     map<long long,int>m;

     for(int i = 0;i<n;i++){
          cin>>arr[i];
          if(i % 2 == 0){
            st.push({count+1,arr[i]});    
            count += arr[i];
          }
          else{
              while(!st.empty() && arr[i] > 0){
                   if(arr[i] > st.top().second){
                      ans += st.top().second;
                       arr[i] -= st.top().second;
                       count += st.top().second;
                       ans += m[st.top().first - 1];
                        st.pop();
                   }
                   else{
                     ans += arr[i];
                     long long  num = st.top().second + st.top().first - 1;
                     ans += m[num - arr[i]];
                     count += arr[i];
                     m[count] = 1 + m[num - arr[i]];
                     long long  k = st.top().second - arr[i];
                     long long  p = st.top().first;
                     arr[i] = 0;
                     st.pop();
                     if(k != 0){
                         st.push({p,k});
                     }
                   }
              }
          }
     }
    cout<<ans<<endl;
}