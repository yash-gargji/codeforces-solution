#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m){
    sort(arr, arr + n);
    int ans = 1e9+7;
  
    for (int i = 0; i + m < n + 1; i++) {
        ans = min(ans,arr[i + m - 1] - arr[i]);
    }
    return ans;
}

int main(){
     int t;
     cin>>t;

}