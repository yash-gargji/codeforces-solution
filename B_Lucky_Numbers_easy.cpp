#include<bits/stdc++.h>
using namespace std;
 
int main(){
    int n;
    cin>>n;
    string a = to_string(n);
    if(a.size()%2 == 1 || a.size() == 10){
         for(int i = 0;i<(a.size()+1)/2;i++){
              cout<<"4";
         }
         for(int i = 0;i<(a.size()+1)/2;i++){
              cout<<"7";
         }
         return 0;
    }
    string s;
     
        for(int i = 0;i<a.size()/2;i++){
              s = s + '4';
         }
           for(int i = 0;i<a.size()/2;i++){
              s = s + '7';
          }
                do {
                string l = s;
                long long int num = stoi(l);
                if(num >= n){
                  cout<<num;
                  return 0;
                }
             } while (next_permutation(s.begin(),s.end()));
     for(int i = 0;i<a.size()/2 + 1;i++){
              cout<<"4";
         }
         for(int i = 0;i<a.size()/2 + 1;i++){
              cout<<"7";
         }
         return 0;
}