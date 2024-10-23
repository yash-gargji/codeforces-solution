 #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int q;
        cin>>q;
        
        vector<int>arr(n);

       for(int i = 0;i<n;i++){
           cin>>arr[i];
       }
       string s;
       cin>>s;
      vector<int>pre(n),suff(n,INT_MAX);
      int ma = 0;
      int mi = INT_MAX;
      set<int>st;

      for(int i = 0;i<n;i++){
            pre[i] = ma;
             ma = max(ma,arr[i]);
      }
      for(int i = n-1;i >= 0;i--){
            suff[i] = mi;
             mi = min(mi,arr[i]);
      }

      for(int i = 0;i<n-1;i++){
         if(s[i] == 'L'  && s[i+1] == 'R'){
             if(suff[i] <= i+1){
                st.insert(i);
             }
             if(pre[i+1] >= i+2)
               st.insert(i+1); 
         }
      }
      for(int i = 0;i<q;i++){
          int num;
          cin>>num;
          num--;
          if(num != 0 && s[num] =='R' && s[num-1] == 'L'){
              int ind = num-1;
             if(suff[ind] <= ind+1){
                st.erase(ind);
             }
             if(pre[ind+1] >= ind+2)
               st.erase(ind+1); 
          }
          else if(num != n-1 && s[num] == 'L' && s[num+1] == 'R'){
                int ind = num;
                if(suff[ind] <= ind+1){
                    st.erase(ind);
                }
                if(pre[ind+1] >= ind+2){
                    st.erase(ind+1); 
                }
          }
          if(s[num] == 'L'){
             s[num] = 'R';
          }
          else 
            s[num] = 'L';

          if(s[num] == 'L' && num != n-1 && s[num+1] == 'R'){
              int ind = num;
              if(suff[ind] <= ind+1){
                st.insert(ind);
             }
             if(pre[ind+1] >= ind+2)
               st.insert(ind+1); 
          }
          else if(num != 0 && s[num] == 'R' && s[num-1] == 'L'){
               int ind = num-1;
              if(suff[ind] <= ind+1){
                st.insert(ind);
             }
             if(pre[ind+1] >= ind+2)
               st.insert(ind+1); 
          }
         if(st.size() > 0)
           cout<<"NO\n";
         else
          cout<<"YES\n";
      }

    }
}