#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        int q;
        cin>>q;
        long long ans = 0;
        vector<int>next(n,-1),prev(n,-1);

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
        for(int i = 0;i<n;i++){
             if(i != 0 && arr[i-1] >= arr[i] && next[i-1] != i){
                prev[i] = i-1;
                ans += arr[i];
             }
             if(i != n-1 && arr[i+1] >= arr[i]){
                next[i] = i + 1;
                ans += arr[i];
             }
        }

        while(q--){
           int ind,num;
           cin>>ind>>num;
           ind--;
           if(ind != 0 && next[ind-1] == ind){
              next[ind-1] = -1;
              ans -= arr[ind-1];
           }
           if(ind != n-1 && prev[ind+1] == ind){
              prev[ind+1] = -1;
              ans -= arr[ind+1];
           }
           if(prev[ind] != -1){
              ans -= arr[ind];
              prev[ind] = -1;
           }
           if(next[ind] != -1){
              ans -= arr[ind];
              next[ind] = -1;
           }
           arr[ind] = num;
           int i = ind;
           if(ind != 0 && arr[ind-1] >= arr[ind]){
                prev[ind] = ind-1;
                ans += arr[i];
             }
            else if(i != 0 && arr[i-1] < arr[i]){
                next[i-1] = i;
                ans += arr[i-1];
            }
           if(ind != n-1 && arr[ind+1] >= arr[ind]){
                next[ind] = ind+1;
                ans += arr[i];
             }
            else if(i != n - 1 && arr[i+1] < arr[i]){
                prev[i+1] = i;
                ans += arr[i+1];
            }
            cout<<ans<<endl;
        }
      
    }
}