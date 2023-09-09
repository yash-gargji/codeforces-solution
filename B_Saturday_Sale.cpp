#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        int n;
        cin>>n;
        int k;
        cin>>k;
        int arr[n];
        map<int,int>m;
        for(int i = 0;i<n;i++){
              int num;
              cin>>num;
             m[num]++;
        }
        int sum = 0;
        for(auto it  = m.begin(); it != m.end() ;it++){
            int num = it->second;
            if(num >= k){
                sum = sum + k;
            }
            else{
                sum += num;
            }
        }
        cout<<sum<<endl;
    
}