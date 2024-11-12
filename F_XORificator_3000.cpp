// #include<bits/stdc++.h>
// using namespace std;

// long long cumulative_xor(long long n) {
//     long long res[] = {n, 1, n + 1, 0};
//     return res[n % 4];
// }

// long long func(long long l, long long r) {
//     return cumulative_xor(r) ^ cumulative_xor(l - 1);
// }

// int main(){
//      int t;
//      cin>>t;
     
//      while(t--){
//          long long l,r,i,k;
//          cin>>l>>r>>i>>k;
//          long long int num = k;
//          int pos = __builtin_ctz(k);
//          long long first_pos = -1,last = -1,slast = -1;

//          for(int i = pos ; i <= 62;i++){
//              long long p = num | (1ll << pos);
//              if(p > r)
//                break;
//              if(p >= l && p % (1ll << i) == k){
//                 first_pos = p;
//                 break;
//              }
//          }
//          if(first_pos == -1){
//             cout<<func(l,r)<<endl;
//          }
//          for(int i = pos ; i <= 62;i++){
//              long long p = num | (1ll << pos);
//              if(p > r)
//                break;
//              if(p >= l && p % (1ll << i) == k){
//                 last = p;
//              }
//          }
//          for(int i = pos ; i <= 62;i++){
//              long long p = last | (1ll << pos) ;
//              if(p > r)
//                break;
//              if(p >= l){
//                 slast
//              }
//          }
         
//      }
// }