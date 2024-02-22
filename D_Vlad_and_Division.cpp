#include<bits/stdc++.h>
using namespace std;

int ones_complement_31(int num) {
    int mask = 0x7FFFFFFF; 
    int complement = ~num & mask;
    
    return complement;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        map<int,int>m;

        for(int  i = 0;i<n;i++){
            int num;
            cin>>num;
            m[num]++;
        }
        int ans = n;
       for(auto &it:m){
        int num = it.first;
        if(it.second == 0) continue;
        int comp = ones_complement_31(num);
        if(m.count(comp)){
          ans = ans - min(m[comp],it.second);
        }
        m[comp] = 0;
       }
       cout<<ans<<endl;
    }
}