// #include<bits/stdc++.h>
// using namespace std; 
 
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds; 
  
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> 

// int main(){
//      int n;
//      cin>>n;

//      int arr[n];
//      map<int,int>m1,m2;
//      vector<int>v;
//      ordered_set st;
//      long long ans = 0;

//      for(int i = 0;i<n;i++){
//          cin>>arr[i];
//          m1[arr[i]]++;
//          v.push_back(m1[arr[i]]);
//          st.insert(m1[arr[i]]);
//      }

//      for(int i = n-1;i >= 0;i--){
//          m2[arr[i]]++;
//          st.erase(st.find(v[i]));
//          ans += st.size() - st.order_of_key(m2[arr[i]] + 1);
//      }
//      cout<<ans<<endl;
// }