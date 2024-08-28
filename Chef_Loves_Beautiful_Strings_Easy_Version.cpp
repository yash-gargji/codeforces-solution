#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int sum = 0;
        long long ans = 0;
        long long int count = 0;

        for(int i = 0;i<n;i++){
            int num = 1;
            for(int j = i+1;j<n;j++ ){
                if(s[j] == s[i]){
                     num++;
                     i = j;
                }
                else{
                    break;
                }
            }
           count ++;
           sum += num - 1;
        }
       ans += sum * (count - 1);
       count -= 2;
       if(count >= 0)
         ans += count*(count + 1)/2;
       cout<<ans<<endl;
    }
}