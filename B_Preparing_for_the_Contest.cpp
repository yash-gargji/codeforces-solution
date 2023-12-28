#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
      while(t--){
          int n;
          cin>>n;
          int k;
          cin>>k;
          vector<int >v(n);
            v[k] = n;
            for(int i = 0;i<k;i++){
                    v[i] = i+1;
            }
            int count = 1;
            for(int i = k + 1; i<n;i++){
                 v[i] = n - count;
                 count++;
            }
            for(int i = 0;i<n;i++){
                 cout<<v[i]<<" ";
            }
            cout<<endl;
      }
}