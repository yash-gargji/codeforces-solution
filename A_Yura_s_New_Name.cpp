#include<bits/stdc++.h>
using namespace std;

int main(){
   int a;
   cin>>a;
   while(a--){
    string s;
    cin>>s;
    int x = s.size();
    int count  = 0;
    if(s[0] == '^' && x == 1){
        cout<<1<<endl;
        continue;
    }
   else if(s[0] == '_'){
     count++;
    }
    if(s[x-1] == '_'){
        count++;
    }
    for(int i = 0;i<x;i++){
        int count1 = 0;
        if(s[i] == '_'){
              int j = i;
              for( j = i;j<x;j++){
                
                if(s[j] == '_'){
                    count1++;
                }
                else{
                    break;
                }
              }
              i = j;
              
              count = count1 - 1 +count;
        }
         
    }
    cout<<count<<"\n";
   }
   return 0;
}