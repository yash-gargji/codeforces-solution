#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    
    while(t--){
         int n,m;
         cin>>n>>m;
         int k;
         cin>>k;
         string s;
         cin>>s;
         int a_cell = 0,b_cell = 0;
         int a = 0;
         int b = 0;
         int curr = 0;
         int ind = 0;

         while(curr < min(n,m)){
             if(s[ind] == 'A'){
                a_cell += n + m - 1;
                a_cell -= 2*a;
                b_cell -= 2*b;
                a++;
             }
             else{
                b_cell += n + m-1;
                a_cell -= 2*a;
                b_cell -= 2*b;
                b++;
             }
            ind = (ind + 1) % k;
            curr++;
         }
        if(a_cell > b_cell){
             cout<<"Alice\n";
        }
        else if(b_cell > a_cell){
            cout<<"Bob\n";
        }
        else{
             cout<<"draw\n";
        }
    }
}