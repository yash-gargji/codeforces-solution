#include<bits/stdc++.h>
using namespace std;

long long func(long long l,long long r,vector<long long>&arr,long long a,long long b){
        auto num = upper_bound(arr.begin(),arr.end(),r) - lower_bound(arr.begin(),arr.end(),l);
        if(num == 0){
           return a;
        }
        else if(r - l + 1 == 1){
           return b*num;
        }
        long long int mid = (r + l)/2;
        long long int num1 = num*(r - l + 1)*b;
        long long int num2 = func(l,mid,arr,a,b) + func(mid+1,r,arr,a,b);

        return min(num1,num2);
}

int main(){
    long long n,k,a,b;
    cin>>n>>k>>a>>b;
    vector<long long>arr(k);

    for(int i = 0;i<k;i++){
        cin>>arr[i];
    }
    sort(arr.begin(),arr.end());
     cout<<func(1,1<<n,arr,a,b);
}