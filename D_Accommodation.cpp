#include<bits/stdc++.h>
using namespace std;

int main(){
   int n,m;
   cin>>n>>m;
   int min_rooms = 0;
   int max_rooms = 0;

   for(int i = 0;i<n;i++){
       string s;
       cin>>s;
       int a = 0,b = 0;
       for(int j = 0;j<m;j++){
          if(s[j] == '0')
            continue;
           int count = 1;
           for(int k = j+1;k<m;k++){
               if(s[k] == '1'){
                 count++;
                 j = k;
               }
               else 
                break;
           }
          int num = min(count/2,m/4 - b);
          b = b + num;
          a += (count - num*2);
       }
       min_rooms += a + b;
       a = 0,b = 0;
       int count = 0;
       vector<int>vis(m),zero,one;
       for(int j = 0;j<m;j++){
          if(s[j] == '0'){
             if(vis[j])
               continue;
              int num = 0;
              for(int k = j;k<m;k++){
                  if(s[k] == '0'){
                      num++;
                      j = k;
                  }
                  else{
                    break;
                  }
              }
             zero.push_back(num);
             continue;
          }
           int num = 1;
           int ind = j;
           for(int k = j+1;k<m;k++){
               if(s[k] == '1'){
                 num++;
                 j = k;
               }
               else 
                break;
           }
           if(b < m/4 && ind - 1 >= 0 && vis[ind-1] == 0){
              num--;
              b++;
              max_rooms++;
              zero[zero.size()-1]--;
           }
           if(b < m/4 && j + 1 < m && num > 0){
              num--;
              b++;
              max_rooms++;
              vis[j+1] = 1;
           }
          count += num;
       }
       for(int i = 0;i<zero.size();i++){
           b += min(m/4 - b,zero[i]/2);
       }
       int temp = min(m/4 - b,count/2);
       max_rooms += temp + (count - 2*temp);
   }
   cout<<min_rooms<<" "<<max_rooms;
   
}