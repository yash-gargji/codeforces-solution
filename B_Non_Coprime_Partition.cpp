 #include<bits/stdc++.h>
using namespace std;

int main(){
     int n;
     cin>>n;
    long long int sum = (n*(n+1))/2;
       for(int i = 2;i<=n;i++){
        if((sum - i)%i == 0){
            cout<<"Yes\n1 "<<i<<endl<<n-1<<" ";
            for(int j = 1;j<= n;j++){
                if(j == i){
                    continue;
                }
                cout<<j<<" ";
            }
            return 0;
        }
       }
       cout<<"No";
}