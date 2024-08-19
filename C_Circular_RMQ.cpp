#include<bits/stdc++.h>
using namespace std;

#define int long long

class SegTree{
public:
	int len;
	vector<int> t, unpropUpd;
	vector<bool> isLazy;
	
	SegTree(){}
	SegTree(int l){
		len = l;
		t.resize(4 * len);
		isLazy.resize(4 * len);
		unpropUpd.resize(4 * len);
	}
	
	void apply(int v, int tl, int tr, int val){
		if(tl != tr){
			isLazy[v] = true;
			unpropUpd[v] += val;
		}
		t[v] += val;
	}
	
	void pushDown(int v, int tl, int tr){
		if(!isLazy[v]) return;
	    	isLazy[v] = false;
		int tm = (tl + tr)/2;
		apply(2*v, tl, tm, unpropUpd[v]);
		apply(2*v+1, tm+1, tr, unpropUpd[v]);
		unpropUpd[v] = 0;
	}
	
	void build(vector<int>& a, int v, int tl, int tr){
		if(tl == tr){
			t[v] = a[tl];
			return;
		}
		int tm = (tl + tr)/2;
		build(a, 2*v, tl, tm);
		build(a, 2*v+1, tm+1, tr);
		t[v] = min(t[2*v] , t[2*v+1]);
	}
	
	int query(int v, int tl, int tr, int l, int r){
		if(tl > r || tr < l) return LLONG_MAX;
		if(l <= tl && tr <= r) return t[v];
		
		pushDown(v, tl, tr);
		int tm = (tl + tr)/2;
		int leftAns = query(2*v, tl, tm, l, r);
		int rightAns = query(2*v+1, tm+1, tr, l, r);
		return min(leftAns,rightAns);
	}
	
	void update(int v, int tl, int tr, int l, int r, int val){
		if(l <= tl && tr <= r){
			apply(v, tl, tr, val);
			return;
		}
		if(tl > r || tr < l) return;
		
		pushDown(v, tl, tr);
		int tm = (tl + tr)/2;
		update(2*v, tl, tm, l, r, val);
		update(2*v+1, tm+1, tr, l, r, val);
		t[v] = min(t[2*v] , t[2*v+1]);
	}
	
	void build(vector<int>& a){
		build(a, 1, 0, len-1);
	}
	
	int query(int l, int r){
		return query(1, 0, len-1, l, r);
	}
	
	void update(int l, int r, int val){
		update(1, 0, len-1, l, r, val);
	}
};

signed main(){
   int n;
   cin>>n;
   vector<int>v(n);

    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    SegTree st(n);
    st.build(v);
    int q;
    cin>>q;
     cin.ignore();
    while(q--){
        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> vec;
        int num;
        while (ss >> num) 
          vec.push_back(num);
        if(vec.size() == 2){
           if(vec[1] < vec[0]){
              cout<<min(st.query(0,vec[1]),st.query(vec[0],n-1))<<endl;
           }
           else{
              cout<<st.query(vec[0],vec[1])<<endl;
           }
        }
        else {
            if(vec[1] < vec[0]){
              st.update(0,vec[1],vec[2]);
              st.update(vec[0],n-1,vec[2]);
           }
           else{
              st.update(vec[0],vec[1],vec[2]);
           }
        }
    }
}