#include<bits/stdc++.h>
using namespace std;

class segmentTree{
public:
    vector<pair<int,int>>sgt;
    vector<int>gcd;

    segmentTree(int n){
         sgt.resize(4 * n);
         gcd.resize(4 * n);
    }

    void build(vector<int>& arr, int ind, int l, int r) {
        if(l == r) {
            sgt[ind] = {arr[l],1};
            gcd[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * ind, l, mid);
        build(arr, 2 * ind + 1, mid + 1, r);

       if(sgt[ind*2].first == sgt[ind*2 + 1].first){
          sgt[ind].second = sgt[ind*2].second +sgt[ind*2+1].second;
          sgt[ind].first = sgt[ind*2].first;
       }
       else if(sgt[ind*2].first < sgt[ind*2 + 1].first){
             sgt[ind] = sgt[ind*2];
       }
       else{
           sgt[ind] = sgt[ind*2+1];
       }
       gcd[ind] = __gcd(gcd[ind*2],gcd[ind*2 + 1]);
    }
 
    pair<int,int> query_min(int l, int r, int ind, int start, int end) {
        if(start > r || end < l)
            return {INT_MAX,0};
        if(l >= start && r <= end)
            return sgt[ind];
        int mid = (l + r) / 2;

        auto left = query_min(l, mid, ind * 2, start, end) ;
        auto right = query_min(mid + 1, r, ind * 2 + 1, start, end);

         if(left.first == right.first){
           return {left.first,left.second + right.second};
       }
       else if(left.first < right.first){
             return  left;
       }
       else{
          return  right;
       }
    }
     int query_gcd(int l, int r, int ind, int start, int end) {
        if(start > r || end < l)
            return  INT_MAX;
        if(l >= start && r <= end)
            return gcd[ind];
        int mid = (l + r) / 2;

        auto left = query_gcd(l, mid, ind * 2, start, end) ;
        auto right = query_gcd(mid + 1, r, ind * 2 + 1, start, end);

         if(left != INT_MAX && right != INT_MAX){
             return __gcd(left,right);
       }
       else if(left != INT_MAX){
             return  left;
       }
       else{
          return  right;
       }
    }    

};

int main(){
      int n;
      cin>>n;
      vector<int>arr(n);
      segmentTree *st = new segmentTree(n);

      for(int i = 0;i<n;i++){
         cin>>arr[i];
      }
    st->build(arr,1,0,n-1);

      int m;
      cin>>m;

      for(int i = 0;i<m;i++){
          int l,r;
          cin>>l>>r;
          l--;
          r--;
          auto p = st->query_min(0,n-1,1,l,r);
          auto gcd = st->query_gcd(0,n-1,1,l,r);

          if(p.first != gcd){
              cout<<r - l + 1 <<endl;
          }
          else{
             cout<<r - l + 1 - p.second<<endl;
          }
      }
}
