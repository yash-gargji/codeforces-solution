#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin>>n;
        long long int sum = 0;
        int k = 0;
        int a = 0;
        int b = 0;
        int chance = 0;

        for(int i = 0;i<n;i++){
            int num;
            cin>>num;
            if(num == 1) k++;
            else sum += num - 2;
        }
        a += k/2;
        b += k/2;
        if(k%2){
            a++;
            chance = 1;
        }
        if(sum%2 == 1 && chance == 1)
        {
            chance = !chance;
        }
        else if(chance == 0 && sum %2 == 1){
              chance = 1;
        }
         if(chance == 1){
            a += n-k;
         }
         else {
            b += n-k;
         }
        if(a == b){
            cout<<"Draw\n";
        }
        else if( a > b){
            cout<<"Alice\n";
        }
        else {
            cout<<"Bob\n";
        }
    }
}
