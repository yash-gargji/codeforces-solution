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
        int zero[n], one[n];
        int count = 0;

        for(int i = 0;i<n;i++){
            if(s[i] == '0'){
                count++;
            }
            zero[i] = count;
        }
         count = 0;
        for(int i = n-1;i >= 0;i--){
            if(s[i] == '1'){
                count++;
            }
            one[i] = count;
        }
        float mid = (float)n/2;
        int ans = -1;
        for(int i = 0;i<n-1;i++){
             int left = i+1;
             int right = n - i - 1;

             if(zero[i] >= (left)/2 + (left)%2 && one[i+1] >= right/2 + right%2 ){
                if(abs((float)i+1 - mid) < abs((float)ans - mid)){
                    ans = i+1;
                }
                else if(abs((float)i+1 - mid) < abs((float)ans - mid)){
                    ans = min(ans,i+1);
                }
             }
        }
        if(one[0] >= n/2 + n%2 && ans == -1){
            ans = 0;
        }
        else if(ans == -1 && zero[n-1] >= n/2 + n%2){
            ans = n;
        }
        cout<<ans<<endl;
    }
}