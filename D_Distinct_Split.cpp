 #include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
          string s;
          cin>>s;
            map<char,int>m1,m2;
          for(int i = 0;i<n;i++){
               m1[s[i]]++;
          }
          int ans = m1.size() + m2.size();
          for(int i = 0;i<n;i++){
              m2[s[i]]++;
              m1[s[i]]--;
              if(m1[s[i]] == 0){
                  m1.erase(s[i]);
              }
               if((m1.size() + m2.size()) >= ans){
                   ans = (m1.size() + m2.size());
               }
          }
          cout<<ans<<endl;
    }
}