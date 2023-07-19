#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
      int t;
      cin>>t;
      
      while(t--){
          int n;
          cin>>n;
             if(n%2 == 1){
                for(int i = 1;i<=n;i++){
                    if(i%2 == 1){
                        cout<<"t";
                    }
                    else{
                        cout<<"o";
                    }
                }
                cout<<endl;
             }
             else if(n == 2){
                cout<<"ta\n";
             } 
             else{
          int num;
          for(int i = 2;i<=26;i++){
                 if(n%i != 0){
                  num = i;
                  break;
                 }
          } 
          string s;
          char c = 'a';
          for(int i = 0;i<num;i++){
              s = s + c;
              c++;
          }  
          for(int i = 0;i<n/num;i++){
            cout<<s;
          }    c = 'a';
          for(int i = 0;i<n%num;i++){
              cout<<c;
              c++;
          }
          cout<<endl;
      }
      }
}