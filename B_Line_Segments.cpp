#include <bits/stdc++.h>
using namespace std;


vector<string> func(vector<vector<string>>& v, int width) {
    vector<string> ans;
    string temp(width + 2, '*');
    ans.push_back(temp);

    for (auto it : v) {
        int ind = 0;
        string s = "";

        while (ind < it.size()) {
              if(it[ind].size() > width)
                continue;
            if (s.empty()) {
                s = it[ind];
            } else if (s.size() + 1 + it[ind].size() <= width) {
                s += " ";
                s += it[ind];
            } else {
                int rem = width - s.size();
                if (rem < 0) rem = 0; 
                int a = rem / 2,b = (rem + 1) /2;
                string lspace(a, ' ');
                string rspace(b, ' ');
                ans.push_back("*" + lspace + s + rspace + "*");
                s = it[ind];
            }
            ind++;
        }

        if (!s.empty()) {
            int rem = width - s.size();
            if (rem < 0) rem = 0; 
             int a = rem / 2,b = (rem + 1) /2;
                string lspace(a, ' ');
                string rspace(b, ' ');
            ans.push_back("*" + lspace + s + rspace + "*");
        }
    }

    ans.push_back(temp);
    return ans;
}


signed main() {
     vector<vector<string>> paragraphs = {
    {"hello", "world"},
    {"How", "areYou", "doing"},
    {"Please look", "and align", "to center"}
};
int width = 16;

auto it = func(paragraphs,width);

for(int i = 0;i<it.size();i++){
     cout<<it[i]<<endl;
}
}
