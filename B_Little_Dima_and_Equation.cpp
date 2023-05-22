#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin>>a>>b>>c;
    set<long long int>s;
    for(int i = 1;i<=81;i++){
        long long int num = 1;
        for(int j = 0;j<a;j++){
            num = num*i;
        }
        num = num*b + c;
        int sum = 0;
       long long int n = num;
        while(n>0){
            sum = sum + n%10;
            n = n/10;
        }
        if(i == sum && num < 1000000000){
            s.insert(num);
        }
    }
    cout<<s.size()<<endl;
    for(auto &value: s){
        cout<<value<<" ";
    }
    return 0;
}