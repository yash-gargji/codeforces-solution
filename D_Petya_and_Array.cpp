// #include<bits/stdc++.h>
// using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<long long, null_type,less_equal<long long>, rb_tree_tag,tree_order_statistics_node_update> 

// int main(){
//     long long int n,k;
//      cin>>n>>k;
//      long long ans = 0;
//      int arr[n];
//      ordered_set st;
//      long long sum = 0;

//      for(int i = 0;i<n;i++){
//          cin>>arr[i];
//          sum += arr[i];
//          if(sum >= k){
//             ans += i+1 - st.order_of_key(sum - k + 1);
//          }
//          else{
//             ans++;
//             ans += st.order_of_key(sum - k);
//          }
//          st.insert(sum);
//      }
    
//     cout<<ans;
// }