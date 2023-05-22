#include<iostream>
using namespace std;

int main(){
      string s;
      cin>>s;
      int x = 0, y= 0;
      for(int i = 0;i<s.size()-1;i++){
         if(s[i] == 'B' && y != 1){
            if(s[i+1] == 'A'){
                y++;
                i = i+1;

            }
         }
         else if(s[i]=='A' && x != 1){
            if(s[i+1] == 'B'){
                x++;
                i = i +1;
            }
          
         }
      }
      int x1 = 0;
      int y1 = 0;
        for(int i = s.size()-1;i>0;i--){
         if(s[i] == 'B' && y1 != 1){
            if(s[i-1] == 'A'){
                y1++;
                i = i-1;

            }
         }
         else if(s[i]=='A' && x1 != 1){
            if(s[i-1] == 'B'){
                x1++;
                i = i-1;
            }
          
         }
      }
      if((x>= 1 && y>= 1)  || (x1 >= 1 && y1 >= 1)){
        cout<<"YES";
      }
      else{
        cout<<"NO";
      }
      return 0;
}
