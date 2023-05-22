#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int x,y;
        cin>>x>>y;
           long long int arr[x];
           for(int i = 0;i<x;i++){
            cin>>arr[i];
           }
           sort(arr,arr+x);
               
              long long int pre[x];
            pre[0] = arr[0];
            for(int i = 1;i<x;i++){
                pre[i] = pre[i-1] + arr[i];
            }
                vector<long long int>vin;

                int f,r;
                f = -1;
                r = x-y-1;
                for(int i = y;i<=2*y;i++){
                     if(f == -1){
                        vin.push_back(pre[r] - 0);
                        
                     }
                     else{
                        vin.push_back(pre[r] - pre[f]);
                     }
                     f = f+2;
                     r  = r+1;
                }
                sort(vin.begin(),vin.end());
                cout<<vin[vin.size() - 1]<<endl;

    }
    return 0;
}