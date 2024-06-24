#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,c;
        cin>>n>>c;
        int arr[n];
        vector<long long int>left_max(n,-1),right_max(n,-1),pre(n);
        long long int num = -1;
        long long int sum = 0;

        for(int i = 0;i<n;i++){
            cin>>arr[i];
            pre[i] = sum + c;
            sum += arr[i];
            left_max[i] = num;
            if(i == 0)
              num = max(num,1ll*arr[i] + c);
            else 
              num = max(num,1ll*arr[i]);
        }
        num = -1;

        for(int i = n-1;i >= 0;i--){
            right_max[i] = num;
            num = max(num,1ll*arr[i]);
        }
        
        for(int i = 0;i<n;i++){
            int ans = 0;
            if(right_max[i] > arr[i]){
               if(arr[i] + pre[i] >= right_max[i]){
                  ans = i;
               }
               else 
                 ans = i+1;
            }
            else if(left_max[i] >= arr[i]){
                 ans = i;
            }
           cout<<ans<<" ";
        }
       cout<<endl;
    }
}