#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    int num = 0,count = 0;
    int arr[n];
    
    multiset<int>s;

    for(int i = 0;i<n;i++){
       cin>>arr[i];
       if(!arr[i])
         count++;
       int k = sqrt(arr[i]);
       if(k * k == arr[i])
          num++;
        if(k * k != arr[i])
        s.insert(min(arr[i] - k*k,(k+1)*(k+1) - arr[i]));
    }
    if(num >= n/2){
        if(count >= n/2)
          count -= n/2;
        else{
            count = 0;
        }
        
        cout<<2*(count) + num - n/2 - count;
    }
    else{
         long long k = 0;
         for(auto it:s){
            if(num == n/2)
              break;
            k += it;
            num++;
         }
        cout<<k<<endl;
    }
    
}