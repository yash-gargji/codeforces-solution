  #include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        int x;
        cin>>x;
        vector<vector<int>>v;

        for(int i = 0;i<x;i++){
            vector<int>temp;
            for(int j = 0;j<5;j++){
                int c;
                cin>>c;
                temp.push_back(c);
            }
            v.push_back(temp);
        }
        vector<pair<int,int>>p;
        int b = 5;
        int count = 0 ;
        for(int i = 0;i<5;i++){
             int sum = 0 ;
             for(int j = 0;j<x;j++){
                sum = sum + v[j][i];
             }
             if(sum >= x/2){
                  count++;
                  p.push_back(make_pair(sum,i));
             }
        }
          
          count = 1;
          if(p.size() <= 2){
            cout<<"NO\n";
            continue;
           }
            sort(p.begin(),p.end());
             int o = 0;
              for(int i = 0;i<x;i++){
                if(o == x/2){
                    break;
                }
                 if(v[i][p[0].second] == 1){
                     o++;
                    for(int j = 0;j<5;j++){
                        if(j == p[0].second){
                            continue;
                        }
                        else if(v[i][j] == 1){
                            v[i][j] = 0;
                          }
                    }
                  }
                 }
            for(int i = 0;i<5;i++){
               if(i == p[0].second){
                continue;
               }
               int sum = 0 ;
                for(int j = 0;j<x;j++){
                 sum = sum + v[i][j];
               }
                if(sum >= x/2){
                  count++;
                   break;
                }
             }
     if(count == 2){
        cout<<"YES\n";
     }
     else{
        cout<<"NO\n";
     }
    }
    return 0;
}