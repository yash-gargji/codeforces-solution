#include<bits/stdc++.h>
using namespace std;

pair<pair<int, int>, double> calculateLineEquation(int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        return {{1, 0}, static_cast<double>(x1)};  
    }
    if (y1 == y2) {
        return {{0, 1}, static_cast<double>(y1)};
    }
    
    int dy = y2 - y1, dx = x2 - x1;
    int flag = 1;
    if((dx < 0 && dy <0 ) && (dy > 0 && dx > 0)){
         flag = 0;
    }
    while(__gcd(dy,dx) != 1){
        int g = __gcd(dy, dx);
        dy /= g;
        dx /= g;
    }
    if((dx < 0 && dy > 0) || (dx > 0 && dy < 0)){
         dy = -abs(dy);
         dx = abs(dx);
    }
    double b =  y1*dx - x1*dy;
    return {{dy, dx}, b};
}

int main(){
    int n;
    cin>>n;

    vector<pair<int,int>>v(n);
    map<pair<pair<int, int>, double>,int>mp;
    map<pair<int, int>,int>k;
    
    for(int i = 0;i<n;i++){
        cin>>v[i].first>>v[i].second;
    }
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            auto p = calculateLineEquation(v[i].first,v[i].second,v[j].first,v[j].second);
            mp[p]++;
        }
    }
    int ans = 0;
    for(auto it:mp){
        k[it.first.first]++;
    }
    for(auto it:k){
       ans += it.second*(it.second - 1)/2;
    }
    cout<<mp.size()*(mp.size()-1)/2 - ans;
    
}