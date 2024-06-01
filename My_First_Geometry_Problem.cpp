#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     
     while(t--){
        string s;
        cin>>s;

        int count = 0;

        for(int i = 0 ;i<4;i++){
             if(s[i] == '1')
              count++;
        }
       if(count == 1)
         cout<<11<<endl;
        else if(count == 3)
          cout<<231<<endl;
        else if(count == 4)
          cout<<441<<endl;
        else if(count == 0)
          cout<<1<<endl;
          else{
              if((s[0] == '1' && s[1] == '1') || (s[2] == '1' && s[3] == '1'))
                cout<<21<<endl;
              else
               cout<<121<<endl;
          }
     }
}