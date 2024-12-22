#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int>freq(m+1),diff(m),r(n);
        
        for(int i = 0;i<n;i++){
           cin>>r[i];
        }
        for(int i = 0;i<m;i++){
           cin>>diff[i];
        }
        sort(diff.begin(),diff.end());
        int k = (upper_bound(diff.begin(),diff.end(),r[0]) - diff.begin());
        
        for(int i = 1;i<n;i++){
           int num = (upper_bound(diff.begin(),diff.end(),r[i]) - diff.begin());
           freq[num]++;
        }
        for(int i = 1;i<=m;i++){
            freq[i] += freq[i-1];
        }
        for(int i = 1;i<=m;i++){
           int temp = k + m % i;
           temp = min(temp,m);
           int num = 0;
           int ind = i;
           
           while(ind <= (m/i)*i){
               if(ind > k && ind <= temp){
                  num += n - 1  - freq[temp];
               }
               else if(ind > temp){
                    num += n - 1  - freq[temp];
                    temp = ind;
               }
               ind += i;
           }
           cout<<num + m/i<<" ";
        }
      cout<<endl;
    }
}