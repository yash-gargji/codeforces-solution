#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,m,q;
    cin>>n>>m>>q;
    
    int arr[n][m];

    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>arr[i][j];  
            if(i != 0){
                arr[i][j] |= arr[i-1][j];
            }
        }
    }
    for(int i = 0;i<q;i++){
        int l = 0;
        int r = n-1;
        int flag = 1;
        int p;
        cin>>p;
        vector<pair<int,int>>it;
        while(p--){
            int r,c;
            char op;
            cin>>r>>op>>c;

            int low = 0;
            int high = n-1;
            int range = -1;
            while(low <= high){
                int  mid = (low + high)/2;

                if(op == '>'){
                    if(arr[mid][r-1] > c){
                        range = mid;
                        high = mid - 1;
                    }
                    else{
                    low = mid + 1;
                    }
                }
                else{
                if(arr[mid][r-1]  < c){
                        range = mid;
                        low = mid + 1;
                    }
                    else{
                        high = mid -1;
                    }
                }
            }
            if(range == -1)
              flag = 0;
            else if(op == '>'){
               it.push_back({range,n-1});
            }
            else{
                it.push_back({0,range});
            }  
        }
        if(flag ){
           sort(it.begin(),it.end());
           for(int i = 0;i<it.size();i++){
               if(it[i].first > r || it[i].second < l){
                  flag = 0;
                  break;
               }
               l = max(l,it[i].first);
               r = min(r,it[i].second);
           }
        }
        if(flag)
          cout<<l+1<<endl;
        else 
          cout<<"-1\n";
    }
    
}