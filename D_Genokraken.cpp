#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
    
        vector<int>ans(n);
        queue<int>q;
        int num = -1;
        for(int i = 2;i<n;i++){
            int r;
            cout<<"? 1 "<<i<<endl;
            cin>>r;
            if(r == 0){
                num = i;
                break;
            }
        }
        
        for(int i = 2;i <= num;i++){
            if(i < num)
               ans[i] = 0;
            else
               ans[i] = 1;
            q.push(i);
        }
        int ind = num+1;
        int count = 0;
        int prev = q.front();
        int prev_parent = -1;
        
        while(ind < n){
             if(prev < prev_parent){
                q.pop();
                prev = q.front();
                continue;
             }
            int r;
            cout<<"? "<<ind<<" "<<prev<<endl;
            cin>>r;
            if(r == 0){
                ans[ind] = prev;
                prev_parent = prev;
                prev = ind++;
            }
            else{
                if(prev != q.front()){
                    q.push(prev);
                }
                q.pop();
                prev = q.front();
            }
        }
        cout<<"! ";
        for(int i = 1;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
  }  
}