#include<bits/stdc++.h>
using namespace std;

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int t;
     cin>>t;
    
    while(t--){
          int l,r;
           cin>>l>>r;
            int sum = 0;
            if(l%2 == 0){
                 sum += l;
            }
            else{
                sum -= l;
            }
            if(l%2 == 0){
                if((r-l)%2 == 0){
                    sum = sum + (r-l)/2;
                }
                else{
                    sum =  sum - r + (r-l)/2;
                }
            }
            else{
                 if((r-l)%2 == 0){
                    sum = sum - (r-l)/2;
                }
                else{
                    sum =  sum + r - (r-l)/2;
                }
            }
            cout<<sum<<endl;
    }
}