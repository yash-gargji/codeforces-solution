#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n;
         cin>>n;
         int x[n],p[n];
         vector<int>left(n),right(n);
         for(int i = 0;i<n;i++){
            left[i] = i;
            right[i] = i;
         }

         for(int i = 0;i<n;i++){
             cin>>x[i];
         }
         for(int i = 0;i<n;i++){
             cin>>p[i];
         }
         if(n == 1){
              cout<<"YES\n"<<endl;
              continue;
         }
         for(int i = 0;i<n-1;i++){
              if(p[i] + x[i] >= x[i+1]){
                  left[i+1] = left[i];
              }
         }
         for(int i = n-1;i > 0;i--){
              if(x[i] - p[i] <= x[i-1]){
                  right[i-1] = right[i];
              }
         }
         int flag = 0;
          if(left[n-1] == 0 || right[0] == n-1){
             flag = 1;
          }

         for(int i = 0;i<n-1;i++){
            if(left[i] == 0 && left[n-1] <= i+1)
                flag = 1;
            if(i > 0 && left[i-1] == 0 && left[n-1] <= i)
                flag = 1;
            if(right[i] == n-1 && right[0] >= i-1)
                flag = 1;
            if( i != n-1 && right[i+1] == n-1 && right[0] >= i)
                flag = 1;
            if(i > 0 && left[i-1] == 0 && right[i] == n-1)
                flag = 1;
            if( left[i] == 0 && i != n-1 && right[i+1] == n-1)
                 flag = 1;
            if(right[0] >=  i-1 && left[n-1] <= i)
                flag = 1;
            if(right[0] >=  i && i != n-1 && left[n-1] <= i+1)
                flag = 1;
           
         }
        if(flag)
          cout<<"YES\n";
        else 
          cout<<"NO\n";
    }
}