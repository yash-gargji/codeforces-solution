#include<bits/stdc++.h>
using namespace std;
void divisor( int n,map< int,int> & m)
{
    int flag = 0;
    for ( int i = 1; i<=sqrt(n); i++)
    {
        if (n%i == 0 ){ 
            flag = 1;
            if (n/i == i)
                m[i]++;
                  
            else{  
                m[i]++;
                 m[n/i]++;
         }
        }
    }
    if(!flag){
        
        m[n]++;
    }
}
int main(){
        int n;
        cin>>n;
        if(n == 1){
            cout<<1;
            return 0;
        }
        map<int, int>m;
        for(int i = 0;i<n;i++){
           int num;
            cin>>num;
            
          divisor(num,m);
        }
        m[1] = 1;
        int ans = 0;
        for(auto it = m.begin();it != m.end();it++){
             int num = it->second;
            ans = max(ans,num);
        }
        cout<<ans;
}