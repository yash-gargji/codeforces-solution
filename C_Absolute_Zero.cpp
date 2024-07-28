#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        set<int> o, e;

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] % 2)
                o.insert(arr[i]);
            else
                e.insert(arr[i]);
        }

         vector<int>v(40,0);
        if (e.size() > 0 && o.size() > 0) {
            cout << "-1\n";
            continue;
        }

        int ind = 0;
        while(ind < 40){
             int num = (*min_element(arr,arr+n) + *max_element(arr,arr+n))/2;
             v[ind++] = num;
             for(int i = 0;i<n;i++){
                 arr[i] = abs(arr[i] - num);
             }
        }
        int ans = 1;
        for(int i = 0;i<n;i++){
            if(arr[i] > 0){
                ans = 0;
                break;
            }
        }
        if (!ans) {
            cout << "-1\n";
        } 
        else {
            cout << 40<< endl;
            for (int i = 0; i < 40; i++) {
                cout << v[i] << " ";
            }
          cout<<endl;
        }
    }

    return 0;
}
