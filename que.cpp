#include<bits/stdc++.h>
using namespace std;

vector<string> func(vector<string>requests,int k){
    
}

string find(vector<string> num){
    map<string,vector<int>>m;
    for(int i=0;i<num.size();i++){
        string s="";
        for(int j=1;j<num[i].size();j++){
             string diff=to_string(num[i][j]-num[i][j-1]);
             s+=diff;
        }
        m[s].push_back(i);
    }
    for(auto it:m){
        if(it.second.size()==1){
            return num[it.second[0]];
        }
    }
}

string f(string s){
    string ans="";
    int n=s.size();
    string temp="";
    for(int i=n-1;i>=0;i--){
        int p=(s[i]-'0')%2;
        int j=i;
        while(i>=0 && (s[i]-'0')%2==p){
            temp+=s[i];
            i--;
        }
        if(j!=i)i++;
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
        ans=temp+ans;
        temp="";
    }
    return temp+ans;
}
int main(){
     

     cout<<f("0082663");
}