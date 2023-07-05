#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int>& a,
        pair<int, int>& b)
{
    return a.second > b.second;
}
int main() {
    int n, m;
    cin >> n >> m;
    int arr[n];
    map<int,int> mp;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }
    for(int j=0;j<m;j++)
    {
        int a, b;
        cin >> a >> b;
        for(int i=a;i<=b;i++)
        {
            mp[i]++;
        }
    }
    vector<pair<int, int>> vec(mp.begin(), mp.end());
    sort(arr, arr + n, greater<int>());
    partial_sort(vec.begin(), vec.begin()+n, vec.end(), cmp);
    long long int sum=0;
    int i=0;
    for (auto &it : vec) {
        sum += it.second*arr[i];
        i++;
    }
    cout << sum << endl;
    return 0;
}