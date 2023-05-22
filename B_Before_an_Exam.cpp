 #include<bits/stdc++.h>
using namespace std;

int main(){
    int x,y;
    cin>>x>>y;
    pair<int, int>p[x];
    int sum1 = 0 ;
    int min1 = 240;
    int sum2 = 0;
    for(int i = 0;i<x;i++){
       cin>>p[i].first;
       cin>>p[i].second;
       sum1 = sum1 + p[i].first;
       sum2 = sum2 + p[i].second;
       min1 = min(min1,p[i].first);
    }
    
    if( y< sum1 || y> sum2){
        cout<<"NO";
        return 0;
    }
    int m = y/x;
    m = m + x - y%x;
    cout<<"YES\n";
    cout<<min1<<" "<<m;
    
     
     
}