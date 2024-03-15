#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        string ans;
        int one = 0;
        int zero = 0;

        for(int i = 0;i<s.size();i++){
            if(s[i] == '1')one++;
        }
        if(k >= one){
            for(int i = 0;i<s.size() - k;i++){
                cout<<"0";
            }
            cout<<endl;
            continue;
        }
         int ind = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                continue;
            } else {
                if (k != 0) {
                    k--;
                    if(k == 0){
                        ind = i+1;
                    }
                } 
                else {
                    break;
                }
            }
        }
        for(int i = 0;i<ind;i++){
            cout<<'0';
        }
        for(int i = ind;i<s.size();i++){
            cout<<s[i];
        }
        cout<<endl;
    }
}
