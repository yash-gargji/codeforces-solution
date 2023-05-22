#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main(){
    int a;
    cin>>a;
    while(a--){
        ll a;
        cin>>a;
       ll arr[a];
         for(int i = 0;i<a;i++){
              cin>>arr[i];
         }
         sort(arr,arr+a);
           ll ax1 = max(arr[0]*arr[1],arr[a-1]*arr[a-2]);
          cout<< ax1<<endl;
    }
    return 0;
}