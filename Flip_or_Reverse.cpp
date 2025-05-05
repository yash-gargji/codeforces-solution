#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;

        string a,b;
        cin>>a>>b;

        vector<vector<int>>v;

        for(int i = 0;i<n;i++){
           if(a[i] == b[i])
             continue;
            int l = i+1;

            for(int j = i;j<n;j++){
                if(a[j] != b[j]){
                   i = j;
                }
                else{
                    break;
                }
            }
            v.push_back({1,l,i+1});
        }
        cout<<v.size()<<endl;

        for(int i = 0;i<v.size();i++){
           cout<<v[i][0]<<" "<<v[i][1]<<" "<<v[i][2]<<endl;
        }
    }
}