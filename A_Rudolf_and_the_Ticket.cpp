#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int m,k;
        cin>>m>>k;

        int arr1[n],arr2[m];
        sort(arr1,arr1+n);
        sort(arr2,arr2+m);
        int count = 0;
        for(int i = 0;i<n;i++){
            cin>>arr1[i];
        }
         for(int i = 0;i<m;i++){
            cin>>arr2[i];
        }

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){

                if(arr1[i] + arr2[j] <= k){
                    count++;
                }
            }
        }
       cout<<count<<endl;
    }
}