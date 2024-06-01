#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
        int n;
        cin>>n;
         string s;
         cin>>s;
        map<int,int>m;
        long long int count = 0;
        int sum = 0;
        
        for(int i = 0;i<s.size();i++){
             if(s[i] == '1')
               sum++;
               else
                  sum--;
                m[sum]++;
               if(sum == 0){
                  count += (m[0])*2 + (i+1  - m[0]);
               }
               else{
                  count += (m[sum] - 1 )*2 + (i + 2 - m[sum]);
               }
              
        }
      cout<<count<<endl;
     }
}