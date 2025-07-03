#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int>spf(1e5 + 1,-1);
    
    for(int i = 2;i<= (int)1e5 + 1;i++){
        if(spf[i] != -1)
           continue;
        for(int j = i;j<= (int)1e5; j += i){
            if(spf[j] == -1)
               spf[j] = i;
        }
    }
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        vector<int>v(n + 1);
        
        for(int i = 0;i<= n;i++){
            v[i] = i;
        }
        for(int i = n;i > 2;i--){
            if(i % 2 == 0){
                swap(v[i],v[i/2]);
            }
            // cout<<v[i]<< " ";
        }
        for(int i = n;i >= 2;i--){
            if(v[i] == i){
               swap(v[i],v[spf[i]]);
            }
        }
        for(int i = 1;i<=n;i++){
            cout<<v[i]<< " ";
        }
        cout<<endl;
    }
}