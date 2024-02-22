#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int r1 = INT_MAX;
        int r2 = -1;
        int c1 = INT_MAX;
        int c2 = -1;

        for(int i = 0;i<n;i++){
            for(int j = 0;j<n;j++){
                 char c;
                 cin>>c;
                if(c == '1'){
                    r1 = min(r1,i);
                    r2 = max(r2,i);
                     c1 = min(c1,j);
                     c2 = max(c2,j);
                }
            }
        }
     if(r2 - r1 == c2 - c1) {
        cout<<"SQUARE\n";
     }
     else{
        cout<<"TRIANGLE\n";
     }
    }
}