#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    map<int,vector<int>>m;
     vector<int>c(n+1),p(n+1);
     for(int i = 1;i<= n;i++){
            int num1,num2;
            cin>>num1>>num2;
             c[i] = num2;
              p[i] = num1;
              m[num1].push_back(i);
     }
      int count = 0;
     for(int i = 1;i<= n;i++){
        if(c[i] == 1 && p[i] != -1){
             if(m.find(i) == m.end()){
                cout<<i<<" ";
                count++;
             }
             else{
                auto val = m[i];
                int flag = 1;
                for(int j = 0;j<val.size();j++){
                   if(c[val[j]] != 1){
                    flag = 0;
                    break;
                   } 
                }
                if(flag){
                    cout<<i<<" ";
                    count ++;
                }
             }
        }
     }
     if(count == 0){
        cout<<"-1 ";
     }
}