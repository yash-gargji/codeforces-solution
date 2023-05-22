#include<bits/stdc++.h>
using namespace std;

int main(){

    int t;
    cin>>t;
    while(t--){
       long int n,m,x,y;
        cin>>n>>m>>x>>y;
         int o = 0;
         int p = 0;
         char arr[n][m];
            for(int i = 0;i<n;i++){
                for(int j = 0;j<m;j++){
                    cin>>arr[i][j];
                }
            }
            
            for(int i = 0;i<n;i++){
               for(int j =0;j<m;j++){
                    if(arr[i][j] == '.' && j+1 != m ){
                        if(arr[i][j+1] == '.'){
                        p++;
                         j = j+1;
                        }
                        else{
                            o++;
                            j = j+1;
                        }
                    }
                    else if(arr[i][j] == '.'){
                        o++;
                    }
               }
            }
            if(2*x <= y){
                cout<<x*(2*p + o)<<endl;
            }
            else{
                cout<<p*y + o*x<<endl;
            }
    }
    return 0;
}