#include<bits/stdc++.h>
using namespace std;

int main(){
     int t;
     cin>>t;

     while(t--){
        int n ;
        cin>>n;
        vector<int>even,odd;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            if(num % 2 == 1)
              odd.push_back(num);
            else
              even.push_back(num);
        }

        if(odd.size() == 0){
           cout<<*max_element(even.begin(),even.end())<<endl;
        }
        else if(even.size() == 0){
            cout<<*max_element(odd.begin(),odd.end())<<endl;
        }
        else{
            long long ans = 1;

            for(int i = 0;i<odd.size();i++){
               ans += odd[i] - 1;
            }
            for(int i = 0;i<even.size();i++){
               ans += even[i];
            }
            cout<<ans<<endl;
        }
     }
}