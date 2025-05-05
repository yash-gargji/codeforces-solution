#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int a,b,c,d;
        cin>>a>>b>>c>>d;
        map<int,int>m;
        m[(a+b)*(a+b)]++;
        m[a*a+c*c]++;
        m[a*a+d*d]++;
        m[b*b+c*c]++;
        m[b*b+d*d]++;
        m[(c+d)*(c+d)]++;
        if(m.size()!=2)cout<<"No"<<endl;
        else {
            int d1=-1,d2=-1;
            for(auto it:m){
                if(d1==-1)d1=it.first;
                d2=it.first;
            }
            if(max(d1,d2)==2*min(d1,d2))cout<<"Yes"<<endl;
            else cout<<"No"<<endl;
        }
    }
}