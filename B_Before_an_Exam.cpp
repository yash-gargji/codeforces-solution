 #include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    pair<int, int>p[x];
    int sum = 0 ;
          vector<int>v(x);
    for(int i = 0;i<x;i++){
       cin>>p[i].first;
       cin>>p[i].second;
       sum = sum + p[i].first;
       v[i] = p[i].first;   
    }
    if(sum > y){
        cout<<"NO";
        return 0;
    }  
     
    for(int i = 0;i<x;i++){
        if(sum == y){
            break;
        }
        int num =  p[i].second - p[i].first;
         if(y - sum >= num){
            sum = sum - v[i];
            v[i] = p[i].second;
            sum = sum + v[i];
         }
         else{
            v[i] = v[i] + y - sum;
              sum = y;
         }
    }
      if(sum == y){
        cout<<"YES\n";
        for(int i = 0;i<x;i++){
            cout<<v[i]<<" ";
        }
        return 0;
    }  
    cout<<"NO";
    return 0;
}