#include<bits/stdc++.h>
using namespace std;
int findUpperBound(vector<pair<int, int> >& arr,
          pair<int, int>& p){
  auto up = upper_bound(arr.begin(), arr.end(), p);
     return up - arr.begin() ;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        long long int n,k;
        cin>>n>>k;
        vector<pair<int,int>>p(n);
        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            p[i].first = num;
        }
          for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            p[i].second = num;
        }
        sort(p.begin(),p.end());
        vector<int>v(n);
        int mi = 1000000;
        for(int i = n-1;i>= 0 ;i--){
            mi = min(mi,p[i].second);
            v[i] = mi;
        }
        long long int num = k;
        int flag = 0;

           for(int i = 0;i<n;i++){
            if(k <= 0 && num < p[n-1].first ){
                flag = 1;
                break;
            }
            if(p[i].first > num ){
                k = k - v[i];
                i--;
                num = num + k;
            }
           }

        string s = flag ? "NO\n":"YES\n";
        cout<< s;
    }
}