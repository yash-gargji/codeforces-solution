#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int x;
        cin>>x;
        string s;
        cin>>s;
        string s1,s2;
        
           if(s[0] == '1'){
            s1 = '2';
            s2 = '2';
           }
            else if(s[0] == '2'){
                s1 = s1 + '1';
                s2 = s2 + '1';
            
            }
            int f ;
            
            for(int i = 1;i<x;i++){
                 if(s[i] != '1' ){
                     f = i;
                    if(s[i] == '2'){
                     s1 = s1 + '1';
                     s2 = s2 + '1';
                    }
                     else if(s[i] == '0'){
                     s1 = s1 + '0';
                     s2 = s2 + '0';
                 } 
                 }
                 else{
                    f = i;
                    s1 = s1 + '1';
                    s2 = s2 + '0';
                    break;
                 }
            }
            for(int i = f+1;i<x;i++){
                   if(s[i] == '1' ){
                      s1 = s1 + '0';
                    s2 = s2 + '1';
                   }
                    else if(s[i] == '2'){
                     s1 = s1 + '0';
                     s2 = s2 + '2';
                    }
                     else if(s[i] == '0'){
                     s1 = s1 + '0';
                     s2 = s2 + '0';
                 } 
            }
            cout<<s1<<endl<<s2<<endl;
    }
}
