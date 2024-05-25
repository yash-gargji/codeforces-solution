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

         while(j < i){
             if(s[j] < s[ind]){
                 flag = 1;
                 break;
             }
             else if(s[ind] < s[j]){
                 break;
             }
             j++;
             ind = (ind+1)%n;
         }
          if(flag)
          {
             ans = i;
             break;
          }
     }
       int num = 0;
        while(num < k/ans){
            cout<<s.substr(0,ans);
            num++;
        }
        for(int i = 0;i<k%ans;i++){
            cout<<s[i];
        }
     
}