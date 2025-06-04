#include<bits/stdc++.h>
using namespace std;

int func(vector<int>v){
    v[0] = 0;
    
       for(int i = 1;i<v.size();i++){
           int num = v[i];
           if(num / 2 > 100){
              v[i] = v[i-1] + 1;
              continue;
           }
           for(int j = num;j > 0;j--){
               if(num % j > v[i-1]){
                  v[i] = min(v[i],num % j);
               }
           }
           if(v[i] <= v[i-1])
             return 0;
       }
    return 1;
}
int main(){
    int t;
    cin>>t;
    
    while(t--){
         int ans = 0;
         int n;
         cin>>n;
         int arr[n];

         for(int i = 0;i<n;i++){
             cin>>arr[i];
         }

         for(int i = 0;i<n;i++){
             vector<int>v;
             for(int j = i;j<n;j++){
                 v.push_back(arr[j]);
                 ans += func(v);
             }
         }
        cout<<ans<<endl;
    }
}