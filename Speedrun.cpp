// #pragma GCC optimize("O3")
// #pragma GCC optimize("Ofast")
#include <bits/stdc++.h>

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
template <class T>
using o_set =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key (val): returns the no. of values less than val
// find_by_order (k): returns the kth largest element.(0-based)
#define int long long
typedef pair<int, int> II;
typedef vector<II> VII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef long long LL;
#define PB push_back
#define F first
#define S second
#define ALL(a) a.begin(), a.end()
#define SET(a, b) memset(a, b, sizeof(a))
#define SZ(a) (int)(a.size())
#define FOR(i, a, b) for (int i = (a); i < (int)(b); ++i)
#define fast_io                                                                \
    ios_base::sync_with_stdio(false);                                          \
    cin.tie(NULL)
#define deb(a) cerr << #a << " = " << (a) << endl;
#define deb1(a)                                                                \
    cerr << #a << " = [ ";                                                     \
    for (auto it = a.begin(); it != a.end(); it++)                             \
        cerr << *it << " ";                                                    \
    cerr << "]\n";
#define endl "\n"
const long long mod = 1e9 + 7;

template <typename T> struct segTree {
    T unit;
    T (*f)(T obj1, T obj2);
    vector<T> s;
    int n;
    segTree(int n, T (*c)(T obj1, T obj2), T def)
        : s(2 * n, def), n(n), f(c), unit(def) {}
    void update(int pos, T val) {
        for (s[pos += n] = val; pos /= 2;)
            s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
    }
    T query(int b, int e) { // query [b, e]
        e++;
        T ra = unit, rb = unit;
        for (b += n, e += n; b < e; b /= 2, e /= 2) {
            if (b % 2)
                ra = f(ra, s[b++]);
            if (e % 2)
                rb = f(s[--e], rb);
        }
        return f(ra, rb);
    }
};
int join(int a, int b) { return max(a, b); }
int sum(int a, int b) { return (a + b); }
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    int k;
    cin >> k;
    VI b(n);
    FOR(i, 0, n) { cin >> a.at(i); }
    FOR(i, 0, n) { cin >> b[i]; }
    swap(a, b);
    int sumH = 0;
    segTree<int> st(n, join, 0);

    segTree<int> sumSt(n, sum, 0);
    FOR(i, 0, n) {
        sumH += a[i];
        st.update(i, sumH - b[i]);
        sumSt.update(i, a[i]);
    }

    FOR(i, 0, n) {
        int goneTill = upper_bound(ALL(b), b[i] + 2 * k) - b.begin() - 1;
        int worst = 0;
        if (i)
            worst = max(worst, st.query(0, i - 1));
        if (goneTill != n - 1)
            worst = max(worst, st.query(goneTill + 1, n - 1) -
                                   sumSt.query(i, goneTill));
        if (worst == 0) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
     int t;
     cin>>t;
     while(t--){
          int n;
        cin >> n;
         int k;
        cin >> k;
        vector<int> a(n),b(n);
        
        for(int i = 0;i<n;i++) { 
            cin >> a.at(i); 
            
        }
        for(int i = 0;i<n;i++) { 
            cin >> b[i]; 
            
        }
        swap(a, b);
        int sumH = 0;
        int ans = 0;
        segTree<int> st(n, join, 0);
    
        segTree<int> sumSt(n, sum, 0);
         for(int i=  0;i<n;i++){
            sumH += a[i];
            st.update(i, sumH - b[i]);
            sumSt.update(i, a[i]);
        }
    
        for(int i = 0;i<n;i++) {
            int goneTill = upper_bound(ALL(b), b[i] + 2 * k) - b.begin() - 1;
            int worst = 0;
            if (i)
                worst = max(worst, st.query(0, i - 1));
            if (goneTill != n - 1)
                worst = max(worst, st.query(goneTill + 1, n - 1) -
                                       sumSt.query(i, goneTill));
            if (worst == 0) {
                cout << "YES\n";
                ans = 1;
                 break;
            }
        }
        if(!ans)
         cout << "NO\n";
    }

    return 0;
}
