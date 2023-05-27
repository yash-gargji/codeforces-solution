#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int t;
    cin>>t;
    while(t--){
   long long int l,e;
    cin>>l>>e;
    map<long long int,long long int>m;
    for(int i = 0;i<e;i++){
        long long int x,y;
        cin>>x>>y;
        m[x]++;
        m[y]++;
    }
    
    map<long long int,long long int>m1;
    for(auto it = m.begin(); it != m.end(); it++){
        long long int num = it->second;
        m1[num]++;
    }
    vector<int> v;
	for (auto p : m1) {
		v.push_back(p.second);
	}
	sort(v.begin(), v.end());
	if (v.size() == 3) {
		cout << v[1] << ' ' << v[2] / v[1] << '\n';
	}
	else {
		cout << v[0] - 1 << ' ' << v[1] / (v[0] - 1) << '\n';
	}
    // pair<long long int,long long int>p[3];
    // int i = 0;
    // for(auto &value: m1){
    //     p[i].first = value.second;
    //     p[i].second= value.first;
    //     i++;
    // }
    // sort(p,p+3);
    // cout<<p[0].second<<" "<<p[1].second-1<<endl;;
        //    int x = v1[0];
        //    int y = v1[1];
        //   if(x == 2){
        //     cout<<x<<" "<<y-1<<endl;
        //   }
        //   else if(y == 2){
        //       cout<<y<<" "<<x-1<<endl;
        //   }
        //   else if(x + (x-1)*y == v){
        //     cout<<y<<" "<<x-1<<endl;
        //   }
        //   else{
        //     cout<<x<<" "<<y-1<<endl;
        //   }
}
return 0;
}