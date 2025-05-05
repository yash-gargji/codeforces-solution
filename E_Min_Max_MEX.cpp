#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
        int low = 0;
        int high = n;

        while(low <= high){
            int mid = (low + high)/2;
            int count = 0;
            unordered_map<int,int>mp;
            int ind = 0;
            
            for(int i = 0;i<n;i++){
                if(arr[i] < n)
                  mp[arr[i]] = 1;
                while(mp.count(ind))
                  ind++;
                if(ind >= mid){
                  unordered_map<int,int>temp;
                    mp = temp;
                    ind = 0;
                    count++;
                }
                if(count >= k)
                  break;
            }
            if(count >= k)
              low = mid + 1;
            else 
              high = mid -1;
        }
        cout<<low - 1<<endl;

        
    }
}