 #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
       int n,m,k;
       cin>>n>>m>>k;
       vector<int>v(n);
       int num = m;
       int ind = n-1;
        for(int i = n-1;i >= 0;i--){
             v[i] = num;
             num--;
             ind--;
             if(num == 0){
                 break;
             }
        }
         num  = n;

         for(int i = 0;i<=ind;i++){
             v[i] = num;
             num--;
         }
        for(int i = 0;i<n;i++){
            cout<<v[i]<<" ";
        }

        cout<<endl;
    }
}