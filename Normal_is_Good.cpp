#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];

        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }
        map<int,vector<int>>m;
        m[0].push_back(0);
        long long int ans = 0;
        int a  = 0,b = 0,c = 0;
        int prev = 0;

        for(int i = 0;i<n;i++){
           if(i != 0 && arr[i] != arr[i-1])
              prev = 0;
            prev++;
            ans += prev;
            int f = 0;
            if(arr[i] == 1){
               a++;
            }
            else if(arr[i] == 3){
                c++;
            }
            else {
                b++;
            }
             
            if(m.find(a-c) != m.end() && a > 0 && c > 0 && b > 0){
                auto it = lower_bound(m[a-c].begin(),m[a-c].end(),b) - m[a-c].begin();
                ans += it;
                if(arr[i] == 2)
                  ans -= prev;
            }
              m[a - c].push_back(b);
        }
       cout<<ans<<endl;
    }
}