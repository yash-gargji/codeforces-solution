#include <bits/stdc++.h>
using namespace std;

void call() {
      vector<int>v(4);

      for(int i = 0;i<4;i++){
         cin>>v[i];
      }

    int ans = 0;
    
    if (v[0] > v[2]) {
        if (v[1] >= v[3]) {
            ans++;
        }
    } else if (v[0] >= v[2]) {
        if (v[1] > v[3]) {
            ans++;
        }
    }
    if (v[0] > v[3]) {
        if (v[1] >= v[2]) {
            ans++;
        }
    } else if (v[0] >= v[3]) {
        if (v[1] > v[2]) {
            ans++;
        }
    }
    if (v[1] > v[2]) {
        if (v[0] >= v[3]) {
            ans++;
        }
    } else if (v[1] >= v[2]) {
        if (v[0] > v[3]) {
            ans++;
        }
    }
    if (v[1] > v[3]) {
        if (v[0] >= v[2]) {
            ans++;
        }
    } else if (v[1] >= v[3]) {
        if (v[0] > v[2]) {
            ans++;
        }
    }
    
    cout << ans << endl;
}

int main() {
    int t; 
    cin >> t;
    while (t--) {
        call();
    }
    
    return 0;
}
