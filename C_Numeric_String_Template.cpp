#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){

        int n;
        cin>>n;
        int arr[n];
        map<int,vector<int>>m;
        
        for(int i = 0;i<n;i++){ 
           cin>>arr[i];
           m[arr[i]].push_back(i);
        }
        int k;
        cin>>k;

        while(k--){
            string s;
            cin >> s;
            
            if(s.size() != n) {
                cout<<"NO\n";
                continue;
            }
            map<char, int> mp1;
            map<int, char> mp2;
            bool flag = true;
            
            for(int j = 0; j < n; j++) {
                if(mp1.find(s[j]) == mp1.end() && mp2.find(arr[j]) == mp2.end()) {
                    mp1[s[j]] = arr[j];
                    mp2[arr[j]] = s[j];
                }
                else if(mp1[s[j]] != arr[j] || mp2[arr[j]] != s[j]) {
                    flag = false;
                    break;
                }
            }
           if(flag){
             cout<<"YES\n";
           }
           else{
            cout<<"NO\n";
           }
        }

    }
}    