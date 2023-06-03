
#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       int t;
       cin>>t;
       while(t--){
           int n;
           cin>>n;
           int arr1[n];
           int arr2[n];
           map<int,int>m1,m2;
           for(int i = 0;i<n;i++){
            cin>>arr1[i];
           }
           for(int i = 0;i<n;i++){
            cin>>arr2[i];
           }
           for(int i = 0;i<n;i++){
            int num = arr1[i];
            int count = 1;
            for(int j = i+1;j<n;j++){
                if(arr1[j] == num){
                    count++;
                    i = j;
                }
                else {
                    break;
                }
            }
            if(m1.find(num) == m1.end()){
                     m1[num] = count;
            }
            else{
                int y = m1[num];
                m1[num] = max(y,count);
            }
           }
            for(int i = 0;i<n;i++){
            int num = arr2[i];
            int count = 1;
            for(int j = i+1;j<n;j++){
                if(arr2[j] == num){
                    i = j;
                    count++;
                }
                else {
                    break;
                }
            }
            if(m2.find(num) == m2.end()){
                     m2[num] = count;
            }
            else{
                int y = m2[num];
                m2[num] = max(y,count);
            }
           }
           vector<int>v;
           for(auto it = m1.begin(); it != m1.end(); it++){
            int num = it->first;
            int x = it->second;
            if(m2.find(num) == m2.end() ){
                v.push_back(x);
            }
            else{
                 int k = it->second + m2[num];
                v.push_back(k);
            }
           }
            for(auto it = m2.begin(); it != m2.end(); it++){
            int num = it->first;
            int x = it->second;
            if(m1.find(num) == m1.end() ){
                v.push_back(x);
            }
            else{
                int k = it->second + m1[num];
                v.push_back(k);
            }
           }
           sort(v.begin(),v.end());
           cout<<v[v.size() - 1]<<endl;
       }
    
}