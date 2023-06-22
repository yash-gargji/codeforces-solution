#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
          int n;
          cin>>n;
          pair<long long int,long long int>p1[n],p2[n];

          for(int i = 0;i<n;i++){
            long long int num;
            cin>>num;
                p1[i] = make_pair(num,i);
          }
            for(int i = 0;i<n;i++){
            long long int num;
            cin>>num;
                p2[i] = make_pair(num,i);
          }
          sort(p1,p1+n);
           sort(p2,p2+n);
              int min = n;
                  int min_array[n];
                  for(int i = n-1;i >= 0 ;i--){
                          if(p2[i].second < min){
                               min = p2[i].second;
                          }
                          min_array[i] = min;
                  }
                  min = n;
                  for(int i = 0;i<n;i++){
                      if(min > p1[i].second + min_array[i]){
                          min =  p1[i].second + min_array[i];
                      }
                  }
                  cout<<min<<endl;
    }
    return 0;
}