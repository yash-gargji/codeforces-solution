#include<bits/stdc++.h>
using namespace std;

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int n,m;
     cin>>n>>m;
        pair<string,string>p[m];
        for(int  i= 0;i<m;i++){
             cin>>p[i].first>>p[i].second;
        }
        for(int i = 0;i<n;i++){
            string s;
            cin>>s;
            for(int j = 0;j<m;j++){
                if(s == p[j].first || s == p[j].second){
                    string s1 = p[j].first;
                    string s2 = p[j].second;
                    if(s1.size() == s2.size()){
                        cout<<s1<<" ";
                    }
                    else if(s1.size() < s2.size()){
                        cout<<s1<<" ";
                    }
                    else{
                        cout<<s2<<" ";
                    }
                }
            }
        }
        return 0;
}