#include <bits/stdc++.h>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>
#include <cassert>
#include <complex>
#include <string>
#include <cstring>
#include <chrono>
#include <random>
#include <bitset>
#include <array>
using namespace std;
#define ll long long
#define pii pair<int, int>
#define pll pair<long long, long long>
#define vi vector<int>
#define vll vector<long long>
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define nl '\n' 
const int N=200007;	
const int MOD=1000000007;
const ll INF = 1e18;
#define iamtefu ios_base::sync_with_stdio(false); cin.tie(0);
 
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());


string binary(ll idx){
	string s;
	for(ll i=63;i>=0;i--){		
		s.push_back(((idx>>i)&1)?'1':'0');
	}

	return s;
}
 
class DisjointSet{

public:
	vector<ll>parent,rank,size;
	DisjointSet(ll n){
	rank.resize(n+1,0);
	parent.resize(n+1);
	size.resize(n+1,1);
	for(ll i=0;i<=n;i++){
		parent[i]=i;
	}
	}
 
ll findpar(ll node){
		if(node==parent[node])return node;
		return parent[node]=findpar(parent[node]);
}
 
void unionrank(ll u,ll v){
	ll pu=findpar(u);
	ll pv=findpar(v);
	if(rank[pu]<rank[pv]){
		parent[pu]=pv;
	}
	else if(rank[pv]<rank[pu]){
		parent[pv]=pu;
	}
	else{
		parent[pv]=pu;
		rank[pu]++;
	}
}
 
void unionsize(ll u,ll v){
	ll pu=findpar(u);
	ll pv=findpar(v);
	if(pu==pv)return;
	else  if(size[pu]<size[pv]){
		parent[pu]=pv;
		size[pv]+=size[pu];
	}
	else{
		parent[pv]=pu;
		size[pu]+=size[pv];
	}
 }
};
 
  
 
double round_to_precision(double value, int precision) {
double scale = pow(10.0, precision);
return round(value * scale) / scale;
}
 

ll expo(ll x, ll n, ll m) {
    ll y = 1;
    while (n) {
        if (n % 2) {
            y = (y * x) % m;
        }
        n = n / 2;
        x = (x * x) % m;
    }
    return y;
}



int main(){		
   int t;
   cin>>t;

   while(t--){
       ll n,d;
        cin>>n>>d;
        ll a[n];
        ll x=0;
        for(ll i=0;i<n;i++){
            cin>>a[i];
            x^=a[i];
        }
        ll al=(x!=0?d+1:d-1);
        ll tot=2*d;
        ll p=expo(tot,MOD-2,MOD);
        cout<<(p*al)%MOD<<nl;
   }
}
