#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        unordered_map<int,int>m;
         
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            m[num]++;
        }
        int count = 0;
        for(auto it:m){
            int num = it.first;
              if(num - 3 == 0 || num % (num - 3) != 0) continue;
                int  k = num/(num - 3);
                 if(!m.count(k)) continue;
                 else if(k == num){
                    if(it.second >= 2){
                        count++;
                    }
                 }
                 else count++;
        }
       cout<<count<<endl;
    }
}