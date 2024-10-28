#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++){
            cin >> arr[i];
            arr[i]--;
        }
        int vis[n + 1]{0};
        int ans = 0;
        function<int(int)> func = [&](int i) -> int{
            int cycle = 0;
            while (!vis[i])
            {
                vis[i] = 1;
                i = arr[i];
                cycle++;
            }
            return cycle;
        };
        for (int i = 0; i < n; i++){
            if (vis[i])
                continue;
            int j = i;
            int cyc = func(j);
            if (cyc <= 2)
                continue;
            cyc--;
            ans += cyc / 2;
        }
        cout << ans << endl;
    }
    return 0;
}