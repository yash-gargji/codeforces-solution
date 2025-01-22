#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,m;
        cin>>n>>m;
        int arr[n][m];

        string s;
        cin>>s;
        vector<int>row(n),col(m);
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                cin>>arr[i][j];
                row[i] += arr[i][j];
                col[j] += arr[i][j];
            }
        }
        int x = 0;
        int r = 0,c = 0;
        
        
        for(int i = 0;i<s.size();i++){
            if(s[i] == 'D'){
                int sum = 0;
               for(int i = 0;i<m;i++){
                  sum += arr[r][i];
               }
               arr[r][c] = x - sum;
               r++;
            }
            else{
                 int sum = 0;
               for(int i = 0;i<n;i++){
                  sum += arr[i][c];
               }
               arr[r][c] = x - sum;
               c++;
            }
        }
        int sum = 0;
        for(int i = 0;i<m-1;i++){
            sum += arr[n-1][i];
        }
        arr[n-1][m-1] = x - sum;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++){
                 cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }
        
    }
}