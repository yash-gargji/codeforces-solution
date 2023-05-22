#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;;
    while(t--){
        int a,x;
        cin>>a>>x;
        pair<int,int>p[a];
        int arr[a];
        int arr1[a];
        for(int i = 0;i<a;i++){
            cin>>p[i].first;
            p[i].second = i;
        }
        for(int i = 0;i<a;i++){
            cin>>arr[i];
        }
        sort(arr,arr+a);
        sort(p,p+a);
        for(int i = 0;i<a;i++){
            arr1[p[i].second] = arr[i];
        }
        for(int i = 0;i<a;i++){
            cout<<arr1[i]<<" ";
        }
        cout<<endl;
    }
}