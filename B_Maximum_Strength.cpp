#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n--){
        int sum = 0;
        string s1,s2;
        cin>>s1>>s2;
        if(s1.size() > s2.size()){
           
                 int flag = 0;
           for(int i = 1;i<s1.size() - s2.size();i++){
                  if(s1[i] != '9'){
                    flag = 1;
                  }
           }
           if(flag == 1){
            sum = s1.size()*9 - 9 + s1[0] - 48 - 1;
           }
           else{
              sum = s1.size()*9 - 9 + s1[0] - 48 ;
           }
        }
        else if(s1.size() == s2.size()){
                for(int i  = 0;i<s1.size();i++){
                    if(s1[i] != s2[i]){
                           int num = s1[i] - s2[i] ;
                               sum = sum + abs(num);
                               sum = sum + 9*(s1.size() - 1 - i);
                               break;
                    }
                }
        }
        else{
                int flag = 0;
           for(int i = 1;i<s2.size() - s1.size();i++){
                  if(s2[i] != '9'){
                    flag = 1;
                  }
           }
           if(flag == 1){
            sum = s2.size()*9 - 9 + s2[0] - 48 - 1;
           }
           else{
              sum = s2.size()*9 - 9 + s2[0] - 48 ;
           }
           }
             cout<<sum<<endl;
        }
        
    return 0;
}