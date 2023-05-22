#include<bits/stdc++.h>
using namespace std;

int main(){
 int a;
 cin>>a;
 while(a--){
       int a;
       cin>>a;
       int arr[a];
       int arr1[a];
       for(int i = 0;i<a;i++){
        cin>>arr[i];
       }
       for(int i = 0;i<a;i++){
        cin>>arr1[i];
       }
       multimap<int,pair<int,int>>m;
       for(int i = 0;i<a;i++){
          int f = i+1;
          int r = i+1;
          int count = 1;
          for(int j = i+1;j<a;j++){
               if(arr1[j] >= arr1[j-1]){
                i = j;
                count++;
                r++;
               }
               else {
                break;
               }
          }
          m.insert({count,{f,r}});
       }
       auto it = m.rbegin();
       int flag = 0;
       for(it = m.rbegin(); it != m.rend();it++){
            auto p = it->second;
            int f = p.first;
            int r = p.second;
            for(int i = f-1;i<r;i++){
                if(arr[i] != arr1[i]){
                    cout<<f<<" "<<r<<endl;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1){
                break;
            }
       }
       if(flag != 1){
        cout<<"1 1\n";
       }  
 }
 return 0;
}