#include<bits/stdc++.h>
using namespace std;

int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        
       long long int n,a,b;
        cin>>n>>a>>b;
        if(b == 1){
            cout<<"Yes\n";
            continue;
        }
        else if(a == 1){
            if((n-1)%b == 0){
                cout<<"Yes\n";
                continue;
            }
            else{
                cout<<"No\n";
                continue;
            }
        }
           long long int c= 1,flag = 0;
            while(c<=n)
            {
                if((n-c)%b==0)
                {
                    cout<<"YES"<<endl;
                    flag=1;
                    break;
                }
                c*=a;
            }
            if(!flag)
            {
                cout<<"NO"<<endl;
            }
    }
    return 0;
}