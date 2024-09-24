#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, d, k;
        cin >> n >> d >> k;

        vector<int>v1,v2;

        for (int i = 0; i < k; i++) {
            int l, r;
            cin >> l >> r;
            v1.push_back(l);
            v2.push_back(r);
        }
        sort(v1.begin(),v1.end());
        sort(v2.begin(),v2.end());
       
      
        int ac = -1;
        int a = -1;
        int bc = INT_MAX;
        int b = -1;

        for(int i = 1;i<=n-d+1;i++){
           int l = i;
           int r = i+d -1;
           int num = k;
           int it = -1;
           int low = 0,high = k-1;

           while(low <= high){
              int mid = (low + high) / 2;
              if(v2[mid] < i){
                 it = mid;
                 low = mid + 1;
              }
              else{
                 high = mid - 1;
              }
           }
           it++;
           auto itr = upper_bound(v1.begin(),v1.end(),r) - v1.begin();
           num = num - (k - itr);  
            
           num -= it;
        //    cout<<it<<" "<<itr<<" "<<num<<endl;
           if(num > ac){
            ac = num;
              a = i;
           }
            if(num < bc){
             bc = num;
              b = i;
           }
        }
       
        cout <<a << " " << b<< endl;
    }

    return 0;
}
