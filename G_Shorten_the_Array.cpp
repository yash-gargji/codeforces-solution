#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* links[2];
    int pc = 0;
     
    bool containKey(int bit){
        return links[bit] != NULL; 
    }
    Node* get(int bit){
        return links[bit];
    }
    void put(int bit,Node *node){
         links[bit] = node;
    }

};
class Trie{
private:
      Node* root;
public:
      Trie(){
         root = new Node();
      } 
     void insert(int num){
        Node *node = root;
        for(int i = 30; i>= 0;i--){
            int bit = (num >> i) & 1;
            if(!node->containKey(bit)){
                node->put(bit,new Node());
            }
            node = node->get(bit);
            node->pc++;
        }
      }
     int getMax(int num){
        Node *node  = root;
         int maxNum = 0;

         for(int i = 30;i >= 0;i--){
              int bit = (num >> i) & 1;

              if(node->containKey(1 - bit) && node->get(1 - bit)->pc > 0){
                  maxNum |= (1 << i);
                  node = node->get(1 - bit);
              }
              else 
                node = node->get(bit);
         }
        return maxNum;
     }
     void erase(int num){
          Node *node = root;
        for(int i = 30; i >= 0;i--){
            int bit = (num >> i) & 1;
            node = node->get(bit);
            node->pc--;
        }
     }
};

int main(){
    int t;
    cin>>t;

    while(t--){
        int n,k;
        cin>>n>>k;
        int arr[n];

        for(int i = 0;i<n;i++){
           cin>>arr[i];
        }
        int ans = INT_MAX;
        
        Trie *tr = new Trie();
        int l = 0;

        for(int i = 0;i<n;i++){
            tr->insert(arr[i]);
            while(l <= i && tr->getMax(arr[i]) >= k){
                 ans = min(ans,i - l + 1);
                 tr->erase(arr[l++]);
            }
        }
        cout<<(ans == INT_MAX ? -1: ans)<<endl;
        

        
    }
}