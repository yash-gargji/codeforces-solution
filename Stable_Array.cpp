#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
     t = 1;
    
    while(t--){
        int n;
        cin>>n;
        vector<pair<string,int>>v(n);
        vector<int>d(n);
        vector<pair<int,int>>pre(n);
        int x = 0,y = 0;
        int dir = 0;

        for(int i = 0;i<n;i++){
            string s;
            cin>>s;
            int num;
            cin>>num;
            v[i] = {s,num};
            d[i] = dir;
            if(dir == 0){
               if(s == "straight")
                  y += num;
                else if(s == "back"){
                    dir = 2;
                    y -= num;
                }
                else if(s == "right"){
                    dir = 1;
                    x += num;
                }
                else{
                    dir = 3;    
                    x -= num;
                }
            }
            else if(dir == 1){
               if(s == "straight")
                   x += num;
                else if(s == "back"){
                    dir = 3;
                    x -= num;
                }
                else if(s == "right"){
                    dir = 2;
                    y -= num;
                }
                else{
                    dir = 0;    
                    y += num;
                }
            }
            else if(dir == 2){
               if(s == "straight")
                  y -= num;
                else if(s == "back"){
                    dir = 0;
                    y += num;
                }
                else if(s == "right"){
                    dir = 3;
                    x -= num;
                }
                else{
                    dir = 1;    
                    x += num;
                }
            }
            else if(dir == 3){
               if(s == "straight")
                  x -= num;
                else if(s == "back"){
                    dir = 1;
                    x += num;
                }
                else if(s == "right"){
                    dir = 0;
                    y += num;
                }
                else{
                    dir = 2;    
                    y -= num;
                }
            }

            pre[i] = {x,y};
        }
       int x1 ,y1,x2,y2;
       cin>>x1>>y1>>x2>>y2;
       x2 -= x1;
       y2 -= y1;
       x1 = 0;
       y1 = 0;
       vector<string>op={"straight","right","left","back"};
       for(int i = 0;i<n;i++){
           int tx = x,ty = y;
           string s = v[i].first;
           int px = 0,py = 0;
           int num = v[i].second;
           if(i != 0){
               tx = x - pre[i-1].first;
               ty = y - pre[i-1].second;
               px = pre[i-1].first;
               py = pre[i-1].second;
           }
           int reqx=x2-px;
           int reqy=y2-py;
           cout<<d[i];
          if(d[i] == 0){
            if(-tx == reqx && -ty == reqy){
                cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[3]<<" "<<v[i].second;
                return 0;
            }
            if(ty == reqx && tx == reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[2]<<" "<<v[i].second;
                return 0;
            }
            if(ty == -reqx && tx == -reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[1]<<" "<<v[i].second;
                return 0;
            }
          }
          if(d[i] == 1){
            if(-tx == reqx && -ty == reqy){
                cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[3]<<" "<<v[i].second;
                return 0;
            }
            if(ty == reqx && tx == reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[1]<<" "<<v[i].second;
                return 0;   
            }
            if(ty == -reqx && tx == -reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[2]<<" "<<v[i].second;
                return 0;
            }
          }
          if(d[i] == 0){
            if(-tx == reqx && -ty == reqy){
                cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[3]<<" "<<v[i].second;
                return 0;
            }
            if(ty == reqx && tx == reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[1]<<" "<<v[i].second;
                return 0;
            }
            if(ty == -reqx && tx == -reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[2]<<" "<<v[i].second;
                return 0;
            }
          }
          if(d[i] == 0){
            if(-tx == reqx && -ty == reqy){
                cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[3]<<" "<<v[i].second;
                return 0;
            }
            if(ty == reqx && tx == reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[1]<<" "<<v[i].second;
                return 0;
            }
            if(ty == -reqx && tx == -reqy){
            cout<<"YES\n";
                cout<<v[i].first<<" "<<v[i].second<<endl<<op[2]<<" "<<v[i].second;
                return 0;
            }
          }
         }
        cout<< "NO\n";
    }
}