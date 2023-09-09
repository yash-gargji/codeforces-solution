#include<bits/stdc++.h>
using namespace std;

int  main(){
    int t;
    cin>>t;
    while(t--){
        int n;
         cin>>n;
         map<long long int,long long int>m;
          vector<long long int>v(n+1,0);

             int count = 0;
           long long int arr[n-1];

           for(int i = 0;i<n-1;i++){
                cin>>arr[i];
            }

              int flag = 0;
           for(int i = 0;i<n-1;i++){
                 if(i == 0){
                      if(arr[0] > n){
                            count++;
                        m[arr[0]]++;
                      }
                      else{
                        m[arr[0]]++;
                        v[arr[0]]++;
                      }
                      continue;
                 }
                 long long int num = arr[i]- arr[i-1];
                     
                if(num > n){
                        count++;
                        m[num]++;
                }
                else{
                  m[num]++;
                    v[num]++;
                }        
           }
           int great = count;
           if( count > 1){
            cout<<"NO\n";
            continue;
           }
           count = 0;
           long long int req = 0;
              
         for(int i = 1;i<=n;i++){
             
               if(v[i] == 0){
                req = req + i;
                count = count + 1;
               }
               else if(v[i] > 2){
                flag = 1;
                  break;
               }
         }
         if(flag == 1){
               cout<<"NO\n";
                  continue;
         }
         if(count >= 3 || count == 0){
              cout<<"NO\n";

         }
         else if(count == 2){
               if(req > n && great == 0 ){
                      cout<<"NO\n";
                      continue;
               }  
               else if(req < n && great == 1 ){
                       cout<<"NO\n";
                       continue;
               }
                auto it = m.find(req);
                   int num = 0;
                if(it == m.end()){
                    m[req] = 0;
                }
                if(req <= n && m[req] != 2 ){
                      cout<<"NO\n";
                       continue;
                }
                else if(req > n && m[req] != 1){
                        cout<<"NO\n";
                       continue;
                }
                else{
                     cout<<"YES\n";
                       continue;
                }   
         }
         else{
            cout<<"YES\n";
         }
    }
}