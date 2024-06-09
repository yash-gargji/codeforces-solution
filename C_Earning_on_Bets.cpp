#include <bits/stdc++.h>
using namespace std;
#define int long long
 
int calculateLCM(int a, int b) {
    return (a / __gcd(a, b)) * b;
}
 
int computeLCM(const vector <int> &numbers) {
    int lcmValue = numbers[0];
     for(int i = 0;i<numbers.size();i++){
        lcmValue = calculateLCM(lcmValue, numbers[i]);
        if (lcmValue == 0) return 0;  
    }
    return lcmValue;
}

 signed main() {
    int t;
    cin>>t;
    while(t--){
            int n;
            cin >> n;
             vector<int>v(n);

            for(int i = 0;i<n;i++) {
                int num;
                cin >> num;
                v[i] = num;
            }
            int lcm = computeLCM(v);
            vector<int>ans;
            int  sum = 0;
            for(int i = 0;i<n;i++){
                 ans.push_back(lcm / v[i]);
                 sum += lcm/v[i];
            }
            int flag = 1;
            for (int i = 0; i < n; i++) {
                if (sum >= ans[i] * v[i]) {
                    cout << -1 << endl;
                    flag = 0;
                    break;
                }
            }
            if(flag){
                 for(int i = 0;i<n;i++){
                      cout<<ans[i]<<" ";
                 }
                  cout<<endl;
            }
           
    }
}