#include<bits/stdc++.h>
using namespace std;

int main(){
   
        int n,m;
        cin>>n>>m;

        if(n == m){
           cout<<"0\n";
           return 0;
        }
        int count  = 1;
        while(m/2 > 0 && n > 0){
            if(n == 1){
                count++;
                break;
            }
            if(n % 2){
              n -= 3;
            }
            else{
                n -= 2;
            }
            m -= 2;
            if(n > 0){
                count++;
            }
        }
        if(m > 0){
           count -= m;
        }
      cout<<max(count,0)<<endl;
    
}