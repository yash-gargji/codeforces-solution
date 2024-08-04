#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        vector<int>o,e;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            if(num%2)
              o.push_back(num);
            else 
             e.push_back(num);
        }
        if(o.size() == 0 || e.size() == 0){
           cout<<"0\n";
           continue;
        }
       sort(o.begin(),o.end());
       sort(e.begin(),e.end());
       int a =  0;
       long long int num = o[o.size() - 1];

       for(int i = 0;i<e.size();i++){
          if(num > e[i]){
              a++;
              num = num + e[i];
          }
          else{
              num += e[i];
              a += 2;
          }
       }
       int b = 0;
       b = e.size() + 1;
        cout<<min(a,b)<<endl;
         
    }
}