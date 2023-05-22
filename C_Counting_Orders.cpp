  #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
       int a;
       cin>>a;
         vector<int>v1,v2;
         for(int i = 0;i<a;i++){
            int num;
            cin>>num;
            v1.push_back(num);
         }
           for(int i = 0;i<a;i++){
            int num;
            cin>>num;
            v2.push_back(num);
         }
         sort(v1.begin(),v1.end());
         sort(v2.begin(),v2.end());
          vector<int>v3;
         unsigned long long int product = 1;
         for(int i = 0;i<a;i++){
          auto it = upper_bound(v1.begin(),v1.end(),v2[i]);
         
               int p = it - v1.begin();
               v3.push_back(a-p);
          
         } 
           sort(v3.begin(),v3.end());
           for(int i = 0;i<v3.size();i++){
              v3[i] =  v3[i] - i;
               
                product = product*v3[i];
                 product = product%(1000000000 + 7);
           }
          
            product = product%(1000000000 + 7);
            cout<<product<<endl;
    }
    return 0;
}