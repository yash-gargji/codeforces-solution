#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
       int n;
       cin>>n;
       set<int>s;
       map<int,set<int>>m;
       int prev = 0;
       int arr[n];
       s.insert(0);
       for(int i = 0;i<n;i++){
           cin>>arr[i];
       }
       sort(arr,arr+n);
       for(int i = 0;i<n;i++){
           m[arr[i] - prev - 1].insert(prev);
           prev = arr[i];
          s.insert(prev);
       }
       s.insert(1e7);
       m[1e7 - prev - 1].insert(prev);
       int q;
       cin>>q;
       while(q--){
          char c;
          int num;
          cin>>c>>num;
          if(c == '-'){
             auto it = s.find(num);
             --it;
             int prev = *it;
             it++;
             it++;
             int front = *it;
             m[num - prev - 1].erase(prev);
             m[front - num - 1].erase(num);
             if(m[num - prev - 1].size() == 0)
                m.erase(num - prev - 1);
             if(m[front- num - 1].size() == 0)
                m.erase(front - num -1);
             s.erase(s.find(num));
             m[front - prev - 1].insert(prev);
          }
          else if(c == '+'){
             auto it = s.upper_bound(num);
             int front = *it;
             it--;
             int prev = *it;
             m[front - prev-1].erase(prev);
             if(m[front- prev - 1].size() == 0)
                m.erase(front - prev -1);
             s.insert(num);
             m[num - prev - 1].insert(prev);
             m[front - num - 1].insert(num);
          }
          else{
            auto it = m.lower_bound(num);
            cout<<*(it->second.begin())+1<<" ";
          }
       }
      cout<<endl;
    }
}