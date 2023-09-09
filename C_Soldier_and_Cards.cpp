 #include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int num1, num2;
    cin >> num1;

    vector<int> v1, v2;
    queue<int> q1, q2;

    for (int i = 0; i < num1; i++) {
        int num;
        cin >> num;
        v1.push_back(num);
        q1.push(num);
    }

    cin >> num2;
    for (int i = 0; i < num2; i++) {
        int num;
        cin >> num;
        v2.push_back(num);
        q2.push(num);
    }

    int count = 0; 

    while (!q1.empty() && !q2.empty()) {
      
        int card1 = q1.front();
        int card2 = q2.front();

        if (card1 > card2) {
            q1.push(card2);
            q1.push(card1);
        } else {
            q2.push(card1);
            q2.push(card2);
        }

        q1.pop();
        q2.pop();

        count++;
 
        if (count > 1000) {
            cout << -1;
            return 0;
        }
    }

    cout << count;
    cout<<" "<< (!q1.size() ? 2:1);
    return 0;
}
