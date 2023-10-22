#include<bits/stdc++.h>
using namespace std;

int main(){
      int n,m;
      cin>>n>>m;
      int minc = INT_MAX;
      int maxc = INT_MIN;
      int minw = INT_MAX;

      for(int i = 0;i<n;i++){
          int num;
          cin>>num;
          minc = min(minc,num);
          maxc = max(maxc,num);
      }
      for(int i = 0;i<m;i++){
          int num;
          cin>>num;
          minw = min(minw,num);
      }
      if(minw <= maxc || minw <= 2*minc){
           cout<<-1;
      }
      else {
         cout<<max(maxc,2*minc);
      }
}