#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        map<int,int>m;
        for(int i = 0;i<a;i++){
            int num;
            cin>>num;
            m[num]++;
        }
        int ans = 0;
        int count  = 0;
        for(auto &value: m){
            int y = value.second;
            ans = max(ans,y);
             count++;
        }
        count = count -1;
        if(count == ans || count == ans-1){
            cout<<count<<endl;
        }
        else if( count < ans){
               cout<<count+1<<endl;
        }
        else{
            cout<<ans<<endl;
        }
    }
    return 0;
}

