#include<bits/stdc++.h>
using namespace std;

int main(){

    string s;
    cin>>s;
     int p = stoi(s);
     if(p<= 74 && p> 47){
        cout<<74;
        return 0;
     }
      int x = 0;
      int  y = 0;

      if(s.size()%2 == 1){
    
    for(int i = 0;i<s.size()/2 +1;i++){
        cout<<4;
    }
    for(int i = s.size()/2 +1;i<s.size() +1;i++){
        cout<<7;

    }
    
      return 0;
      }
      int f = 0;
      
      int flag  = 0;
      int d  = 0;
      int num = 0;
      int big;
      int small;
    for(int i = 0;i < s.size()/2;i++){
        if(s[i] -48 == 7){
             f++;
        }
        else if(s[i] -48 > 7){
              flag = 1;
               big = i;
              d++;     
        }
        else if(s[i] -48 < 4){
            big = i;
        }
    }
    int num2 = 0;  
      for(int i = 0;i < s.size();i++){
        if(s[i] -48 == 7){
             num++;
        }  
        else if(s[i] -48 == 4){
             num2++;
        }  
        else if(s[i] -48 > 7){
              flag = 1;
               big = i;
              d++;     
        }
        else if(s[i] -48 < 4){
            big = i;
        } 
    }  
    if(num == num2 && num == s.size()/2){
        cout<<s;
        return 0;
    }
    else if((num == s.size()/2 && num2 ==  s.size()/2 -1) ||( num == s.size()/2-1 && num2 ==  s.size()/2) ){
         if(s[big] - 48 < 4 && num2 ==  s.size()/2 -1 ){
            s[big] = '4';
            cout<<s;
            return 0;
         }
         else{
            if(s[big] - 48 < 7 && num == s.size()/2-1){
                s[big] = '7';
                cout<<s;
                return 0;
            }
            else{
          int size = s.size() +2;
                for(int i = 0;i<size/2 ;i++){
                   cout<<4;
               }
             for(int i = size/2 ;i<size;i++){
                    cout<<7;
               
               }
                return 0;
            }
         }
    }
   else if(f +d == s.size()/2 ){
          int size = s.size() +2;
                for(int i = 0;i<size/2 ;i++){
                   cout<<4;
               }
             for(int i = size/2 ;i<size;i++){
                    cout<<7;
               
               }
                return 0;
       }
    else if(num>= s.size()/2){
        int g ;
        int flag = 0;
           for(int i = 0;i<s.size()/2+1;i++){
            if(s[i] -48 <4){
                g = i;
                  flag = 1;
                  break;  
            }
           }
           if(flag == 0){
            int size = s.size() +2;
                for(int i = 0;i<size/2 ;i++){
                   cout<<4;
               }
             for(int i = size/2 ;i<size;i++){
                    cout<<7;
               
               }
                return 0;
           }
           else{
              for(int i = 0;i<s.size();i++){
                  if(i != g){
                     if(s[i] - 48 == 4){
                            x++;
                     }
                     else if(s[i] - 48 == 7){
                            y++;
                        }
                  }
                  else{
                    s[g] = '4';
                    x++;
                    break;
                  }  
              }
              int y ;
              for(int i = g+1;i<g+1 + s.size()/2 - x;i++){
                s[i] = '4';
                y = i;
              }
              for(int i = g+1 + s.size()/2 - x;i<s.size();i++){
                s[i] = '7';
              }
              cout<<s;
              return 0;
           }
    }
     
      for(int i = 0;i<s.size() ;i++){
           if(s[i] - 48 == 4){
            x++;
           }
           else if(s[i] - 48 == 7){
            y++;
           }
           else{
            if(s[i] - 48 < 4){
                s[i] = '4';
                x++;
                break;
            }
            else if(s[i] - 48 < 7){
                s[i] = '7';
                y++;
                break;
            }
            else{
               int size = s.size() +2;
                for(int i = 0;i<size/2 ;i++){
                   cout<<4;
               }
             for(int i = size/2 ;i<size;i++){
                    cout<<7;

               }
                return 0;
            }
         }
      }
      int a = s.size()/2-x;
      int b = s.size()/2 - y;

      for(int i = x+y;i< a + x+y;i++){
           s[i] = '4';
      }
        for(int i =a+ x+y;i< a+b+ x+y;i++){
           s[i] = '7';
      }
      cout<<s;
      return 0;
}