#include <bits/stdc++.h>
using namespace std;

 
int main(){
    int n, m;
    cin >> n >> m;
  long long int arr[n];
   
    for(int i = 0;i<n;i++){
        cin >> arr[i];
    }
    vector<long long int>diff(n+1,0);
    
    for(int j = 0;j<m;j++){
        int a,b;
        cin >> a >> b;
        diff[a-1] += 1;
         diff[b] -= 1;
    }
    for(int i = 1;i<n;i++){
        diff[i] += diff[i-1];
    }
     sort(arr,arr+n,greater<int>());

     sort(diff.begin(),diff.end(),greater<int>());
     
     long long int sum = 0;
     
     for(int i = 0;i < n;i++){
        long long int num = diff[i]*arr[i];
           sum += num;
     }
     cout<<sum;
}