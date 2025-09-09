#include <bits/stdc++.h>
using namespace std;

char* GetSubstring(char* input1, char* input2) {
    string s = input1;
    string t = input2;

    if (s.empty() || t.empty()) {
        char* res = new char[1];
        res[0] = '\0';
        return res;
    }

    unordered_map<char, int> need;
    for (char c : t) need[c]++;

    int required = need.size();
    int formed = 0;
    unordered_map<char, int> window;
    int l = 0, r = 0;
    int minLen = INT_MAX, start = 0;

    while (r < (int)s.size()) {
        char c = s[r];
        window[c]++;
        if (need.count(c) && window[c] == need[c]) {
            formed++;
        }
        while (l <= r && formed == required) {
            if (r - l + 1 < minLen) {
                minLen = r - l + 1;
                start = l;
            }
            char d = s[l];
            window[d]--;
            if (need.count(d) && window[d] < need[d]) {
                formed--;
            }
            l++;
        }
        r++;
    }

    string ans = (minLen == INT_MAX) ? "" : s.substr(start, minLen);
    char* res = new char[ans.size() + 1];
    strcpy(res, ans.c_str());
    return res;
}

int main() {
    // Test case 1
    char input1_1[] = "I am the greatest";
    char input2_1[] = "imt";
    char* result1 = GetSubstring(input1_1, input2_1);
    cout << "Input1: " << input1_1 << endl;
    cout << "Input2: " << input2_1 << endl;
    cout << "Output: " << result1 << endl;
    delete[] result1;

    // Test case 2
    char input1_2[] = "me is Fr";
    char input2_2[] = "rim";
    char* result2 = GetSubstring(input1_2, input2_2);
    cout << "Input1: " << input1_2 << endl;
    cout << "Input2: " << input2_2 << endl;
    cout << "Output: " << result2 << endl;
    delete[] result2;

    // Additional custom test case
    char input1_3[] = "AABBC";
    char input2_3[] = "ABC";
    char* result3 = GetSubstring(input1_3, input2_3);
    cout << "Input1: " << input1_3 << endl;
    cout << "Input2: " << input2_3 << endl;
    cout << "Output: " << result3 << endl;
    delete[] result3;

    return 0;
}
