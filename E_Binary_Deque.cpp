#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
           int n,s;
           cin>>n>>s;
     int arr[n];
     int sum = 0;
     for(int i = 0;i<n;i++){
           cin>>arr[i];
           sum += arr[i];
     }
     if(sum == s){
        cout<<"0\n";
     }
     else if(s > sum){
        cout<<"-1\n";
     }
     else{
        int f = -1,r = n ;
           int k = 0;
           int ans = n;
            vector<int>front,rear;
          for(int i  = 0;i<n;i++){
                k = k + arr[i];
                if(arr[i] == 1){
                  front.push_back(i);
                }
                if(sum - k == s){
                    f = i;
                    break;
                }
          }
          k = 0;
          for(int i  = n-1;i>= 0;i--){
                k = k + arr[i];
                    if(arr[i] == 1){
                  rear.push_back(i);
                }
                if(sum - k == s){
                    r = i;
                    break;
                }
          }
          ans = min(ans,f +1);
           ans = min(ans,n - r);
           front.pop_back();
           int i = 0;
          while(front.size() != 0){
                    f = front[front.size()-1];
                    front.pop_back();
                      r = rear[i];
                    i++;
                    ans = min(ans,(n-(r-f-1)));
          }
          cout<<ans<<endl;
     }
    }
}