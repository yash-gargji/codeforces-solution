#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
     int n,a,b;
     cin>>n>>a>>b;
     int ans = 0;
     int p = abs(a-b);
     pair<int,int>v[n];
     for(int i = 0;i<n;i++){
        int num;
        cin>>num;
         if(i<a){
           v[i] = {num,-1};
         }
         else{
            v[i] = {num,1};
         }
     }
     sort(v,v+n);
     int l = 0,r = 0;
     for(int i = 0;i<n;i++){
     int x = 0;
     int y = 0;
        int num = v[i].first;
        if(v[i].second == 1){
            y++;
        }
        else{
            x++;
        } 
        for(int j = i+1;j<n;j++){
              if(v[j].first == num){
                i = j;
                if(v[j].second == -1){
                    x++;
                }
                else{
                    y++;
                }
              }
              else{
                break;
              }
        }
        if(min(x,y) == x){
            y = y-x;
            if(b>a ){
                if(p >= y){
                    p = p - y + y%2;
                    ans = ans + y/2;
                     r += y%2;
                }
                else {
                      ans = ans + p/2;
                       y = y-p;
                    p = 0;              
                    r += y;
                }
            }
            else{
               r += y;
            }
        }
        else{
            x = x - y;
            if(a>b){
                if(p >= x){
                    p = p - x +x%2;
                    ans = ans + x/2;
                    l = l + x%2;
                }
                else{
                     ans = ans + p/2;
                    x = x - p;
                    p = 0;
                    l = l + x;
                }
            }
            else{
                l = l + x;
            }
        }
     }
     ans = ans + min(l,r) + abs(l-r);
        cout<<ans<<endl;
    }
    return 0;
}