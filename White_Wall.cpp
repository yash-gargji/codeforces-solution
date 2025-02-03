#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;

        vector<string>v = {"RGB","RBG","GRB","GBR","BRG","BGR"};

        int ans = INT_MAX;

        for(int i = 0;i<6;i++){
            int num = 0;
            int ind = 0;

            for(int j = 0;j<n;j++){
                if(s[j] != v[i][ind])
                   num++;
                ind = (ind + 1) % 3;
            }
            ans = min(ans,num);
        }
      cout<<ans<<endl;
    }
}