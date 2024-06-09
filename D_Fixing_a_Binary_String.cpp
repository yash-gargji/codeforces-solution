#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;

    while (t--){
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int prev = -1, ind = -1;
        
        for (int i = 0; i < n; i++){
            int count = 1;
            for (int j = i + 1; j < n; j++){
                if(count == k)
                  break;
                if(s[i] == s[j]){
                    count++;
                    i = j;
                }
                else
                    break;
            }
            ind = i + 1;
            if(prev != -1 && s[i] - '0' == prev){
                ind = ind - k;
                break;
            }
            if (count != k)
                break;
            prev = s[i] - '0';
        }
        if(ind == n){
            int f = 0;
             for(int i = 0;i<n;i++){
                 if(s[i] != s[n-1]){
                   cout<<i+k<<endl;
                   f = 1;
                   break;
                 }
             }
            if(!f) cout<<ind<<endl;

            continue;    
        }
        int f = 1;
        string num = s.substr(0, ind);
        reverse(num.begin(), num.end());
        s += num;
        prev = -1;

        for (int i = ind; i < s.size(); i++){
            int count = 1;
            for(int j = i + 1; j < s.size(); j++){
                 if(count == k)
                    break;
                if (s[i] == s[j]){
                    count++;
                    i = j;
                }
                else
                    break;
            }
            if(count != k || (prev != -1 && s[i] - '0' == prev)){
                f = 0;
                break;
            }
            prev = s[i] - '0';
        }
        if (f)
            cout << ind << endl;
        else
            cout << -1 << endl;
    }
}