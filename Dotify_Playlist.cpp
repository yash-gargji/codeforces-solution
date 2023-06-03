#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k,l;
        cin>>n>>k>>l;
        vector<int>v;
        for(int i = 0;i<n;i++){
            int x,y;
            cin>>x>>y;
            if(y == l){
                v.push_back(x);
            }
        }
        int num = 0;
        sort(v.begin(),v.end());
         int sum = 0;
        for(int i = v.size()-1;i>=0;i--){
            if(num == k){
                break;
            }
                sum = sum + v[i];
                num++;
        }
        if(num != k){
            cout<<"-1\n";
        }
        else{
            cout<<sum<<endl;
        }
    }
}