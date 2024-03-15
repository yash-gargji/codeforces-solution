#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
         
        vector<int>v(n);

        for(int i = 0;i<n;i++){
            cin>>v[i];
        }
       stack<int>st;
       vector<int>ans = v;
       int flag = 1;
       int ind = 1;
        st.push(v[0]);
         while(ind != n){
             if(v[ind] >= st.top()){
                st.push(v[ind]);
             }
             else{
                 stack<int>st1;
                 st1.push(v[ind]);
                 while(!st.empty()){
                    int num = st.top();
                    st.pop();
                    if(num <= st1.top()){
                        st1.push(st1.top());
                    }
                    int a = num%10;
                    num = num/10;
                    if(st1.top() < a){
                        flag = 0;
                        break;
                    }
                    if(num != 0){
                        int b = num%10;
                        if(a < b){
                            flag = 0;
                            break;
                        }
                        else {
                            st1.push(a);
                            st1.push(b);
                        }

                    }
                    else{
                        st1.push(a);
                    }
                 }
                if(flag == 0) break;
                else {
                    while(!st1.empty()){
                        st.push(st1.top());
                        st1.pop();
                    }
                }
             }
             ind++;
         }
        if(flag == 0) cout<<"NO\n";
        else{
           cout<<"YES\n";
        }
      }
    }