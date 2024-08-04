// #include<bits/stdc++.h>
// using namespace std;
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// int main(){
//      int n;
//      cin>>n;
//      long long ans = 0;
//      int arr[n];
//      long long pre[n];
//      ordered_set st1,st2;

//      for(int i = 0;i<n;i++){
//          cin>>arr[i];
//          pre[i] = i - st1.order_of_key(arr[i]);
//          st1.insert(arr[i]);
//      }
//      for(int i = n-1;i >= 0;i--){
//          long long num = st2.order_of_key(arr[i]);
//          st2.insert(arr[i]);
//          ans += num*pre[i];
//      }
//     cout<<ans;
// }