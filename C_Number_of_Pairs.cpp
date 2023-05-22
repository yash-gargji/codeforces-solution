#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,l,r;
        cin>>n>>l>>r;
        vector<long long int>v;
        for(int i = 0;i<n;i++){
            long long int num;
            cin>>num;
            if(num >= r){
                continue;
            }
            v.push_back(num);
        }
        sort(v.begin(),v.end());
        long long int sum = 0;
        for(int i = 0;i<v.size();i++){
          long long int low,high;
            high = r - v[i];
            low = l - v[i];
            
             auto it = lower_bound(v.begin(),v.end(),low) - v.begin();
             auto itr = upper_bound(v.begin(),v.end(),high) - v.begin();
             sum = sum + itr - it;

             if(v[i]+v[i] >= l && v[i]+v[i] <= r){
                sum = sum-1;
             }
        }
        cout<<sum/2<<endl;
    }
}