#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    pair<int,int>p[n];
    int sum1 = 0;
    int sum2 = 0;
    for(int i = 0;i<n;i++){
        int x,y;
        cin>>x>>y;
        sum1 = sum1 +x;
        sum2  = sum2 + y;
        p[i] = {x,y};
    }
    if(sum1%2 == 0 && sum2 %2 == 0){
        cout<<0;
        return 0;
    }
    for(int i = 0;i<n;i++){
        if((sum1 - p[i].first + p[i].second)%2 == 0 && (sum2 + p[i].first - p[i].second)%2 == 0){
            sum1 = 0;
            sum2 = 0;
            break;
        }
    }
    if(sum1 == 0 && sum2 == 0){
        cout<<1;
    }
    else{
        cout<<-1;
    }
}