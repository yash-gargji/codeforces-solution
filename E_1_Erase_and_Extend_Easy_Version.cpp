 #include<bits/stdc++.h>
using namespace std;

int  main(){
     int n,k;
     cin>>n>>k;
     string s;
     cin>>s;
     int ans = n;

     for(int i = 1;i<n;i++){
         int flag = 0;
         int ind = i;
         int j = 0;
         int count = 0;

         while(count < i){
            count++;
             if(s[j] < s[ind]){
                 flag = 1;
                 break;
             }
         }
     }
}