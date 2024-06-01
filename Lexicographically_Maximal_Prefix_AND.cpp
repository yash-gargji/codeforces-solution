#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* links[2];
    int a = 0, b = 0;

    bool containKey(int bit) {
        return links[bit] != NULL;
    }
    Node* get(int bit) {
        return links[bit];
    }
    void put(int bit, Node *node) {
        links[bit] = node;
    }
};

class Trie {
private:
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    ~Trie() {
        clear(root);
    }
    void clear(Node* node) {
        if (!node) return;
        clear(node->links[0]);
        clear(node->links[1]);
        delete node;
    }
    void insert(int num) {
        Node *node = root;
        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (!node->containKey(bit)) {
                node->put(bit, new Node());
            }
            node = node->get(bit);
            if (bit == 1)
                node->b++;
            else
                node->a++;
        }
    }
    int getMax(int num) {
        Node *node = root;
        int maxNum = 0;

        for (int i = 30; i >= 0; i--) {
            int bit = (num >> i) & 1;
            

            if (bit == 1) {
                if (node->containKey(1) && node->get(1)->b > 0) {
                    maxNum |= (1 << i);
                    node = node->get(1);
                    node->b--;
                } else if (node->containKey(0) && node->get(0)->a > 0) {
                    node = node->get(0);
                    node->a--;
                } else {
                    return 0;
                }
            } else {
                int num1 = 0, num2 = 0;
                if (node->containKey(0) && node->get(0)->a > 0) {
                    num1 = func(num, i - 1, node->get(0));
                } else if (node->containKey(1) && node->get(1)->b > 0) {
                    num2 = func(num, i - 1, node->get(1));
                } else {
                    return 0;
                }
                if (num1 >= num2) {
                    node = node->get(0);
                    node->a--;
                } else {
                    node = node->get(1);
                    node->b--;
                }
            }
        }
        return maxNum;
    }
    int func(int num, int ind, Node *k) {
        if(k == NULL)
          return 0;
        Node *node = k;
        int maxNum = 0;

        for (int i = ind; i >= 0; i--) {
            int bit = (num >> i) & 1;
            if (bit == 1) {
                if (node->containKey(1) && node->get(1)->b > 0) {
                    maxNum |= (1 << i);
                    node = node->get(1);
                } else if (node->containKey(0) && node->get(0)->a > 0) {
                    node = node->get(0);
                } else {
                    return 0;
                }
            } else {
                int num1 = 0, num2 = 0;
                if (node->containKey(0) && node->get(0)->a > 0) {
                     num1 = func(num, i - 1, node->get(0));
                } else if (node->containKey(1) && node->get(1)->b > 0) {
                    num2 = func(num, i - 1, node->get(1));
                } else {
                    return 0;
                }
                return max(num1 + maxNum, num2 + maxNum);
            }
        }
        return maxNum;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;
        Trie *tr = new Trie();
        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            tr->insert(arr[i]);
        }

        int num  = *max_element(arr,arr+n);
        for (int i = 0; i < n; i++) {
             num = tr->getMax(num);
            cout << num << " ";
        }
        cout << endl;

        delete tr;
    }
}
