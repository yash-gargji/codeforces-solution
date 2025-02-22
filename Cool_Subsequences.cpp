#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;


        map<int,int>m;
        int ans = -1;
        for(int i = 0;i<n;i++){
             int num;
             cin>>num;
             if(m.count(num))
               ans = num;
             m[num]++;
        }
        if(ans != -1){
          cout<<1<<endl;
        }
        cout<<ans<<endl;
    }
}