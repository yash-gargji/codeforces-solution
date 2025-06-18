#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>a(n),b(n);

        for(int i = 0;i<n;i++){
           cin>>a[i];
        }
        for(int i = 0;i<n;i++){
           cin>>b[i];
        }

        int low = *min_element(a.begin(),a.end()),high = 2e9;

        while(low <= high){
             int mid = (low + high)/2;
             int fl = 1;
             int count = 0,sum = 0;

             for(int i = 0;i<n;i++){
                if(a[i] > mid){
                    fl = 0;
                    break;
                }
                 int num = min(mid - a[i],b[i]);
                 count += b[i] - num;
                 sum += (mid - a[i] - num)/2;
             }
             if(fl == 0 || count > sum){
                 low = mid + 1;
             }
             else {
                high = mid - 1;
             }
        }
       cout<<high+1<<endl;
    }
}