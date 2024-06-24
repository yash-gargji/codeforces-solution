#include<bits/stdc++.h>
using namespace std;

class segmentTree{
public:
    vector<int>sgt;

    segmentTree(int n){
         sgt.resize(4 * n);
    }

    void build(vector<int>& arr, int ind, int l, int r,int flag) {
        if(l == r) {
            sgt[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        build(arr, 2 * ind, l, mid,!flag);
        build(arr, 2 * ind + 1, mid + 1, r,!flag);

        if(flag == 0)
         sgt[ind] = sgt[2 * ind] | sgt[2 * ind + 1]; 
        else 
          sgt[ind] = sgt[2 * ind] ^ sgt[2 * ind + 1]; 
    }

    void update(vector<int>& arr, int ind, int l, int r, int pos, int val,int flag) {
        if(l == r) {
            arr[pos] = val;
            sgt[ind] = arr[l];
            return;
        }
        int mid = (l + r) / 2;
        if(pos <= mid)
            update(arr, 2 * ind, l, mid, pos, val,!flag);
        else
            update(arr, 2 * ind + 1, mid + 1, r, pos, val,!flag);

        if(flag == 0)
          sgt[ind] = sgt[2 * ind] | sgt[2 * ind + 1]; 
        else 
          sgt[ind] = sgt[2 * ind] ^ sgt[2 * ind + 1]; 
    }

    int query(int l, int r, int ind, int start, int end) {
        if(start > r || end < l)
            return 0;
        if(l >= start && r <= end)
            return sgt[ind];
        int mid = (l + r) / 2;

        return query(l, mid, ind * 2, start, end) + query(mid + 1, r, ind * 2 + 1, start, end);
    }
};

int main(){
     int n,m;
     cin>>n>>m;
     int num = pow(2,n);
     vector<int>arr(num);
     segmentTree *st = new segmentTree(num);
     int flag = 0;
     if(n%2 == 0)
       flag = 1;

     for(int i = 0;i<num;i++){
         cin>>arr[i]; 
     }
     st->build(arr,1,0,num-1,flag);

     for(int i = 0;i<m;i++){
         int p,a;
         cin>>p>>a;
         st->update(arr,1,0,num-1,p-1,a,flag);
         cout<<st->sgt[1]<<endl;
     }
}
