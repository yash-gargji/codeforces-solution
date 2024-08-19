#include<bits/stdc++.h>
using namespace std;

class SegTree{
public:
	int len;
	vector<int> unpropUpd;
    vector<vector<int>> t;
	vector<bool> isLazy;
	
	SegTree() {}
	SegTree(int l){
		len = l;
		t.resize(4 * len, vector<int>(32));
		isLazy.resize(4 * len);
		unpropUpd.resize(4 * len);
	}
	
	void apply(int v, int tl, int tr, int val){
		if (tl != tr) {
			isLazy[v] = true;
			unpropUpd[v] ^= val;
		}
		int k = 0;
		while (k < 31) {
			if (val & (1 << k)) {
				t[v][k] = (tr - tl + 1) - t[v][k];
			}
			k++;
		}
	}
	
	void pushDown(int v, int tl, int tr){
		if (!isLazy[v]) return;
		isLazy[v] = false;
		int tm = (tl + tr) / 2;
		apply(2 * v, tl, tm, unpropUpd[v]);
		apply(2 * v + 1, tm + 1, tr, unpropUpd[v]);
		unpropUpd[v] = 0;
	}
	
	void build(vector<int>& a, int v, int tl, int tr){
		if (tl == tr) {
			int k = 0;
			while (k < 31) {
				t[v][k] = (a[tl] >> k) & 1;
				k++;
			}
			return;
		}
		int tm = (tl + tr) / 2;
		build(a, 2 * v, tl, tm);
		build(a, 2 * v + 1, tm + 1, tr);
	    
		for (int i = 0; i < 32; i++) {
			t[v][i] = t[2 * v][i] + t[2 * v + 1][i];
		}
	}
	
	long long query(int v, int tl, int tr, int l, int r){
		if (tl > r || tr < l) return 0;
		if (l <= tl && tr <= r) {
			long long num = 0;
			for (int i = 0; i < 31; i++) {
				num += (1LL << i) * t[v][i];
			}
			return num;
		}
		
		pushDown(v, tl, tr);
		int tm = (tl + tr) / 2;
		long long leftAns = query(2 * v, tl, tm, l, r);
		long long rightAns = query(2 * v + 1, tm + 1, tr, l, r);
		return leftAns + rightAns;
	}
	
	void update(int v, int tl, int tr, int l, int r, int val){
		if (l <= tl && tr <= r) {
			apply(v, tl, tr, val);
			return;
		}
		if (tl > r || tr < l) return;
		
		pushDown(v, tl, tr);
		int tm = (tl + tr) / 2;
		update(2 * v, tl, tm, l, r, val);
		update(2 * v + 1, tm + 1, tr, l, r, val);
		for (int i = 0; i < 32; i++) {
			t[v][i] = t[2 * v][i] + t[2 * v + 1][i];
		}
	}
	void build(vector<int>& a){
		build(a, 1, 0, len - 1);
	}
	long long query(int l, int r){  
		return query(1, 0, len - 1, l, r);
	}
	void update(int l, int r, int val){
		update(1, 0, len - 1, l, r, val);
	}
};
int main(){
    int n;
    cin >> n;
    vector<int> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    SegTree st(n);
    st.build(v);

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        if (num == 1) {
            int l, r;
            cin >> l >> r;
            l--; r--;
            cout << st.query(l, r) << endl;
        } else {
            int l, r, val;
            cin >> l >> r >> val;
            l--; r--;
            st.update(l, r, val);
        }
    }
}
