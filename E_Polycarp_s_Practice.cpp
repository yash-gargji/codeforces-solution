#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
            int n,k;
            cin>>n>>k;
            int sum = 0;

             int arr[n];
             int dup[n];

             for(int i = 0;i<n;i++){
                cin>>arr[i];
                dup[i] = arr[i];
             }
             vector<int>v;
                 
             
             sort(dup,dup+n);
   
              int i = n-1; 
                int num = k;
                while(num--){
                    
                    sum += dup[i];
                    for(int j = 0;j < n-1 ;j++){
                        if(dup[i] == arr[j]){
                            auto it = find(v.begin(),v.end(),j+1);
                            if(it == v.end()){
                              v.push_back(j+1);
                             break;
                            }
                        }
                    }
                    i--;
                } 
                 v.push_back(0);
                   v.push_back(n);
                sort(v.begin(),v.end());

                cout<<sum<<endl;

                for(int j = 1;j<=k;j++){
                     if(j == k){
                        cout<<n-v[j-1]<<" ";
                        return 0;
                     }
                    cout<<v[j]-v[j-1]<<" ";
                }
            
       
}