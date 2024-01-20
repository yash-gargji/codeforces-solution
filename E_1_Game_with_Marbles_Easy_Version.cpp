#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<int>a(n),b(n);
        vector<pair<int,int>>diff;
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
             a[i] = num;
        }
         for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            b[i] = num;
            diff.push_back({a[i] - b[i],i});
        } 
         sort(diff.begin(),diff.end());
    }
}