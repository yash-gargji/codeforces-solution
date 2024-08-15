#include <bits/stdc++.h>
using namespace std;

void updateMatrix(vector<vector<int>>& mat, int x1, int y1, int x2, int y2, int val) {
    mat[x1][y1] += val;
    if (x2 + 1 < mat.size()) {
        mat[x2 + 1][y1] -= val;
    }
    if (y2 + 1 < mat[0].size()) {
        mat[x1][y2 + 1] -= val;
    }
    if (x2 + 1 < mat.size() && y2 + 1 < mat[0].size()) {
        mat[x2 + 1][y2 + 1] += val;
    }
}

vector<vector<int>> computePrefixSum(const vector<vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    
    vector<vector<int>> prefix_sum(rows + 1, vector<int>(cols + 1, 0));
    
    for (int i = 1; i <= rows; ++i) {
        for (int j = 1; j <= cols; ++j) {
            prefix_sum[i][j] = matrix[i - 1][j - 1]
                               + prefix_sum[i - 1][j]
                               + prefix_sum[i][j - 1]
                               - prefix_sum[i - 1][j - 1];
        }
    }
    
    return prefix_sum;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int p;
        cin >> p;
        
        vector<long long> v(p);
        for (int i = 0; i < p; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());

        vector<vector<int>> mat(n, vector<int>(m, 0));
        
        for (int i = 0; i <= n - k; ++i) {
            for (int j = 0; j <= m - k; ++j) {
                updateMatrix(mat, i, j, i + k - 1, j + k - 1, 1);
            }
        }

        vector<vector<int>> pre = computePrefixSum(mat);
        priority_queue<int> pq;

        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                pq.push(pre[i][j]);
            }
        }

        long long ans = 0;
        vector<int> topValues;
        while (!pq.empty()) {
            topValues.push_back(pq.top());
            pq.pop();
        }
        sort(topValues.begin(), topValues.end(), greater<int>());
        
        for (int i = 0; i < p; ++i) {
            ans += topValues[i] * v[p - 1 - i];
        }
        
        cout << ans << endl;
    }

    return 0;
}
