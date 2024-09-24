#include<bits/stdc++.h>
using namespace std;

#define ll long long 
#define nl endl

int main(){
    int t;
    cin>>t;
    
    while(t--){
        ll n,k;
	cin>>n>>k;
	ll start=n-k+1;
	if(start%2){
		ll el=(n-start)/2+1;
		if(el%2)cout<<"NO"<<nl;
		else cout<<"YES"<<nl;
	}
	else{
		if(k==1)cout<<"YES"<<nl;
		else{
		ll el=(n-start-1)/2+1;
		if(el%2)cout<<"NO"<<nl;
		else cout<<"YES"<<nl;
		}
	}
    }
}
