 #include <bits/stdc++.h>
using namespace std;

int getsum(int n) {
    int sum = 0;
    while (n != 0) {
        sum = sum + n % 10;
        n = n / 10;
    }
    return sum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        vector<int> v;
        int arr[n];
        
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] > 9) {
                v.push_back(i);
            }
        }
        
        for (int i = 0; i < q; i++) {
            int num, f, r;
            cin >> num;
            if (num == 1) {
                cin >> f >> r;
                auto it = lower_bound(v.begin(), v.end(), f - 1) - v.begin();
                
                if (it == v.size()) {
                    continue;
                }
                while (it < v.size() && v[it] < r) {  
                    int sum = getsum(arr[v[it]]);
                    arr[v[it]] = sum;
                    
                    if (arr[v[it]] <= 9) {
                        v.erase(v.begin() + it);
                    } else {
                        it++;  
                    }
                }
            } else {
                cin >> num;
                cout << arr[num - 1] << endl;
            }
        }
    }
}
