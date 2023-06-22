#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v1,v2;
    long long int sum1 = 0,sum2 = 0;
    int s;
    for(int i = 0;i<n;i++){
        int num;
        cin>>num;
        if(i == n-1){
            s = num;
        }
        if(num >= 0){
            sum1 = sum1 + num;
            v1.push_back(num);
        }
        else{
              sum2 = sum2 - num;
            v2.push_back(-num);
        }
    }
    if(sum1 > sum2){
        cout<<"first";
        return 0;
    }
    else if(sum1 < sum2){
        cout<<"second";
        return 0;
    }

      n = min(v1.size(),v2.size());
     for(int i = 0;i<n;i++){

            if(v1[i] > v2[i]){
          cout<<"first";
          return 0;
          }
     else if(v1[i] < v2[i]){
          cout<<"second";
          return 0;
         }
     }
      if(s >= 0 ){
        cout<<"first";
        
    }
    else{
        cout<<"second";
    
    }
}