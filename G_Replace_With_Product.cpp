#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        vector<double> arr(n);
        vector<int> v;
        double sum = 0, prod = 1, ans = 0;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            sum += arr[i];
            if (arr[i] > 1) {
                v.push_back(i); 
            }
            if (prod < 1e25) {
                prod *= arr[i];
            }
        }

        if(v.size() <= 1) {
            cout << "1 1\n";
            continue;
        }  
         else if (prod >= 1e6) {  
            cout << v[0] + 1 << " " << v[v.size() - 1] + 1 << endl;
            continue;
        }

        int l = v[0], r = v[v.size() - 1];
        ans = prod + v[0] + n -  v[v.size() - 1] - 1; 
      
        if(sum >= ans){
            cout<<"1 1\n";
            continue;
        }
        for(int i = 0;i<v.size();i++){
           double num = arr[v[i]];
           double k = sum - arr[v[i]];

           for(int j = i+1;j<v.size();j++){
                k = k - (v[i] - v[i-1]) + 1 - arr[v[j]];
               num *= arr[v[j]];
               if(k + num > ans){
                  ans = k + num;
                  l = v[i];
                  r = v[j];
               }
           }
        }
        cout << l + 1 << " " << r + 1 << endl;
    }
    return 0;
}
