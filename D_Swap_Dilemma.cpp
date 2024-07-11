#include <bits/stdc++.h>
using namespace std;

bool canMakeSame(vector<int>& a, vector<int>& b, int n) {
    // Create position mappings for array b
    unordered_map<int, int> posB;
    for (int i = 0; i < n; ++i) {
        posB[b[i]] = i;
    }

    // A visited array to mark matched elements
    vector<bool> visited(n, false);

    for (int i = 0; i < n; ++i) {
        if (visited[i]) continue;
        
        int start = i;
        while (start < n && visited[start]) ++start;
        if (start >= n) break;

        int end = start;
        unordered_set<int> positionsInB;

        // Collect positions for the current segment in a and b
        while (end < n && !visited[end]) {
            positionsInB.insert(posB[a[end]]);
            visited[end] = true;
            ++end;
        }

        vector<int> segmentA(a.begin() + start, a.begin() + end);
        vector<int> segmentB;
        for (int idx : positionsInB) {
            segmentB.push_back(b[idx]);
        }

        // Sort segments and compare
        sort(segmentA.begin(), segmentA.end());
        sort(segmentB.begin(), segmentB.end());

        if (segmentA != segmentB) {
            return false;
        }
    }
    
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        vector<int> b(n);
        
        for (int i = 0; i < n; ++i) {
            cin >> a[i];
        }
        for (int i = 0; i < n; ++i) {
            cin >> b[i];
        }

        if (canMakeSame(a, b, n)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}
