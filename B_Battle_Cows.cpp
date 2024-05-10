#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
void solve() {
    int n,k;
    cin>>n>>k;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int temp=arr[k-1],index=0;
    for(int i=0;i<k-1;i++){
        if(arr[i]>arr[k-1]){
            arr[k-1]=temp;
            arr[i]=temp;
            index=i;
            break;
        }
    }
    int ct1=0,ans=arr[0];
    for(int i=1;i<n;i++){
        ans=max(ans,arr[i]);
        if(ans==temp){
            ct1++;
        }
        else if(ans>temp)break;
    }
    cout<<max(ct1,index-1)<<endl;
}
int main() {
    int t;
    t=1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}