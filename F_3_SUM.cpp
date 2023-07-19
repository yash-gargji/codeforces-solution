#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;
     while(t--){
          int n;
          cin>>n;
          map<int,int>m;
            
          for(int i = 0;i<n;i++){
                 int num;
                  cin>>num;
                  m[num%10]++;
          }
           
          int flag = 0;
            for(int i = 0;i<= 9;i++){
                if(m.find(i) == m.end()){
                    continue;
                } 
                m[i]--;
                if(m[i] == 0){
                    m.erase(m.find(i));
                }
                for(int j = 0;j<=9;j++){
                       if(m.find(j) == m.end()){
                        continue;
                       }
                       m[j]--;
                        if(m[j] == 0){
                          m.erase(m.find(j));
                       }
                       if(m.find(3-i-j) != m.end() || m.find(13-i-j) != m.end() || m.find(23 - i - j) != m.end()){
                            flag = 1;
                            break;
                       }
                       m[j]++;
                }
                if(flag){
                    break;
                }
                m[i]++;
            }
            cout<< (flag ? "YES\n":"NO\n");
     }
}