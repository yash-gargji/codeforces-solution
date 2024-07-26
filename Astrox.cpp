#include<bits/stdc++.h>
using namespace std;

long long dp[100000][5][2];

int pow(char a){
      int count = 1;

      for(char i = 'A' ;i<='E';i++){
          if(i == a){
             break;
          }
          count = count*10;
      }
    return count;
}

long long func(int ind, char a, int op, string &s) {
    if(ind < 0) {
        return 0;
    }
    if(dp[ind][a - 'A'][op] != -1) {
        return dp[ind][a - 'A'][op];
    }

    long long num = pow(s[ind]);
    if(s[ind] < a) {
        num = -num + func(ind - 1, a, op, s);
    } else {
        num = num + func(ind - 1, s[ind], op, s);
    }

    long long mod = LLONG_MIN;
    if(op == 1) {
        for(char i = a; i <= 'E'; i++) {
            if(s[ind] == i) {
                continue;
            }
            long long k = pow(i) + func(ind - 1, i, 0, s);
            mod = max(mod, k);
        }
    }

    return dp[ind][a - 'A'][op] = max(mod, num);
}

int main() {
    string s = "AAAA";
    memset(dp, -1, sizeof(dp));

    cout << func(s.size() - 1, 'A', 1, s);
}
