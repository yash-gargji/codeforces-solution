#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        string s;
        cin>>s;

        stack<char>sa;  
         int f = 0;
         int r = 0;
        int count  = 0;
        for(int i =  0;i<s.size();i++){
            if(s[i] == '?'){
                count++;
            }
            else if(s[i] == '('){
                f = i;
                sa.push('(');
            }
            else{
                r = i;
                sa.push(')');
            }
        }
        if(count%2 == 1 || s[0] == ')' || s[s.size() - 1] == '('){
         cout<<"NO\n";
         continue;
        }
         
        else {
            cout<<"YES\n";
        }
    }
    return 0;
}