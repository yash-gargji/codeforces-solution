#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        
        vector<int>arr(n);
        vector<int>vis(n+1);
        
        for(int i = 1;i<=n;i++){
            int ind = 0;
            int fl = 0;
            while((1 << ind) <= i){
                if(((1 << ind) & i) > 0 && ((1 << ind) & x) == 0 ){
                    fl = 1;
                    break;
                }
                ind++;
            }
            if(fl)
              continue;
            int num = i^x;
            if(num == 0){
               arr[i-1] = i;
               vis[i] = 1;
            }
            else if(num <= n){
               arr[i-1] = num;
               vis[num] = 1;
            }
        }
        int i = 0,j = 1;

        while(i < n && j <= n){
             if(i != n && arr[i] != 0){
                i++;
                continue;
             }
             if(j != n + 1 && vis[j] != 0){
                j++;
                continue;
             }
             arr[i] = j;
             i++;
             j++;
        }
       
        
        for(int i = 0;i<n;i++){
            if(arr[i] != 0)
               cout<<arr[i]<<" ";
        }
      cout<<endl;
    }
}
