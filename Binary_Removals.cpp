#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n,k,x;
        cin>>n>>x>>k;
        string s;
        vector<int>v;
        cin>>s;
  		for(int i=0;i<n;i++){
  			if(s[i]=='0')v.push_back(i);
  		}
  		int ans=0;
  		for(int i=0;i<n;i++){
  			if(s[i]=='1'){
                auto it=lower_bound(v.begin(),v.end(),i)-v.begin();
               if(it<v.size())ans+=v.size()-it;
            }
  			
  		}
  		if(ans<=x && ans%k==0)
          cout<<"1\n";
  		else cout<<2<<endl;
    }
} 