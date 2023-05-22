#include<bits/stdc++.h>
#include<algorithm>
using namespace std;

int main(){
       ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2 == 0){
            cout<<n/2<<" "<<n/2<<endl;
        }
        else if(n == 3 || n == 2){
            cout<<"1 "<<n-1<<endl;
        }
        else{
                 set<int>s;
                 int x,y;
                 for(int i = 3;i*i<= n;i = i+2){
                      if(n%i == 0){
                        s.insert(i);
                        int y = n/i;
                        if(n%y == 0){
                            s.insert(y);
                            break;
                        }
                      }
                 }
                 if(s.size() == 0){
                     cout<<"1 "<<n-1<<endl;
                 }
                 else{
                  auto it = s.end();
                  it--;
                  x = (*it);
                  y = n- x;
             cout<<x<<" "<<y<<endl;
                 }
        }
    }
    return 0;
}