#include <bits/stdc++.h>
using namespace std;
   
int main() {
   
    int t;
    cin >> t;

    while (t--) {
         int n;
         cin>>n;
         string s;
         cin>>s;

         if(n == 1){
           cout<<"NO\n";
           continue;
         }
         else if(n  == 2)
        {
            if(s == "SS" || s == "NN" || s == "WW" || s == "E"){
                 cout<<"RH\n";
            }
            else 
              cout<<"NO\n";
            continue;
        }
       vector<int>v(4);
       for(int i = 0;i<n;i++){
           if(s[i] == 'N')
             v[0]++;
            else if(s[i] == 'S')
             v[1]--;
            else if(s[i] == 'W')
             v[3]--;
             else
              v[2]++;
       }
    if(abs(v[1] - v[0])%2 || abs(v[2] - v[3])%2){
         cout<<"NO\n";
         continue;
    }
      vector<int>r(4);
      vector<int>h(4);
      if(v[0] == v[1]){
          r[0] = (v[0]+ 1)/2;
          r[1] = (v[0] + 1)/2;
          h[0] = v[0]/2;
          h[1] = v[1]/2;
      }
      else if(v[0] > v[1]){
          int num = abs(v[0] - v[1])/2;
          r[0] = (v[0])/2 - num;
          r[1] = 0;
          h[0] = v[0] - r[0];
          h[1] = v[1];
      }
      else{
          int num = abs(v[0] - v[1])/2;
          r[1] = (v[1])/2 - num;
          r[0] = 0;
          h[1] = v[1] - r[1];
          h[0] = v[0];
      }
       if(v[2] == v[3]){
          r[2] = (v[2]+ 1)/2;
          r[3] = (v[3] + 1)/2;
          h[2] = v[2]/2;
          h[3] = v[3]/2;
      }
      else if(v[2] > v[3]){
          int num = abs(v[2] - v[2])/2;
          r[2] = (v[2])/2 - num;
          r[3] = 0;
          h[2] = v[2] - r[2];
          h[3] = v[3];
      }
      else{
          int num = abs(v[2] - v[3])/2;
          r[3] = (v[3])/2 - num;
          r[2] = 0;
          h[3] = v[3] - r[2];
          h[2] = v[2];
      }
      for(int i = 0;i<n;i++){
           if(s[i] == 'N'){
              if(r[0]){
               cout<<"R";
               r[0]--;
              }
               else{
                cout<<"H";
                h[0]--;
               }
           }
            else if(s[i] == 'S'){
                 if(r[1]){
               cout<<"R";
               r[1]--;
              }
               else{
                cout<<"H";
                h[1]--;
               }
            }
              
            else if(s[i] == 'W'){
                 if(r[3]){
               cout<<"R";
               r[3]--;
              }
               else{
                cout<<"H";
                h[3]--;
               }
            }
             
             else
            {
                if(r[2]){
               cout<<"R";
               r[2]--;
              }
               else{
                cout<<"H";
                h[2]--;
               }
            }
      }
     cout<<endl;
    }

    return 0;
}
