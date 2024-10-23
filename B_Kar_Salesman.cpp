#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while(t--){
        int n, r;
        cin>>n>>r;

        vector<int> v(n);
        long long sum = 0;

        for(int i = 0; i < n; i++){
            cin >> v[i];
            sum += v[i];
        }
        long long result = max(1ll*(*max_element(v.begin(), v.end())), 1ll*(sum / r + (sum % r != 0 ? 1 : 0)));
        if(r >= n ){
             result = *max_element(v.begin(), v.end());
        }
        
        cout << result << endl;
    }
}
