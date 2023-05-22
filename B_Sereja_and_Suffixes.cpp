#include<bits/stdc++.h>
using namespace std;


int main(){

     ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     long int a,b;
      cin>>a>>b;
     set<int>s;
    vector<int>v;

    int arr[a];
    pair<int,int>p[a];
    for(int i = 0;i<a;i++){
        cin>>arr[i];
    }
    for(int i = a-1;i>=0;i--){
         s.insert(arr[i]); 
           v.push_back(s.size());
    }
    while(b--){
         int d;
         cin>>d;
           cout<<v[a-d]<<endl;
    }
   
     return 0;
}
