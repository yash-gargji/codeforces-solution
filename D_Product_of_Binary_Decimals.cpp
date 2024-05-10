#include<bits/stdc++.h>
using namespace std;

#define ll long long int

int sol(int num){
    while(num>0){   
        if(num % 10 ==1 || num % 10 ==0){
             num = num/10;
            continue;
        }
        return 0;
    }
    return 1;
}

void check(vector<int>& vec){
    
    for(int i=1;i<=100000 + 5;i++){
        if(sol(i) == 1){
            vec.push_back(i);
        }
    }
}

int main(){
    vector<int> vec;
    check(vec);
    
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int size = vec.size()-1;

        while(n>0 && size > -1){
            if(n%vec[size]==0 && vec[size] != 1){
                n=n/vec[size];
                continue;
            }
            size = size - 1;
        }
        string s = n >= 2 ? "NO" : "YES";
        cout<<s<<endl;
    }
    
    return 0;
}
