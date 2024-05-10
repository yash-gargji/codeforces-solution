// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
     int t;
      cin>>t;
      
      while(t--){
           int n;
           cin>>n;
           string s;
           cin>>s;
           
           int a = 0;
           int b = 0;
           int sum = 0;
           
           for(int i = 0;i<s.size();i++){
                 if(s[i] == '1'){
                     int num = 1;
                     
                     for(int j = i+1; j<s.size();j++){
                          if(s[j] == '1'){
                              num++;
                              i = j;
                          }else break;
                       }
                       if(num == 2){
                            a++;
                       }
                       else if(num%2 == 1){
                            b++;
                       }
                     }
                 }
                if(b%2 == 1){
                     cout<<"NO\n";
                }
                else if(a%2 == 1 && b == 0){
                      cout<<"NO\n";
                }
                else{
                     cout<<"Yes\n";
                }
           }
            
}