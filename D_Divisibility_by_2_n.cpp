#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a;
        cin>>a;
        int arr[a];
         int odd = 0;
           int pow = 0;
        for(int i = 0;i<a;i++){
            cin>>arr[i];
            if(arr[i]%2 == 1){
                odd++;
            }
            else{
                int y = -1;
                int num = arr[i];
               while(num%2 != 1){
                    y++;
                    num = num/2;
               }
               pow = pow+ y;
            }
        }
             multiset<int>s;
             for(int i = 2;i <= a; i= i + 2){
                         int y = 0;
                int num = i;
               while(num%2 != 1){
                    y++;
                    num = num/2;
               }
                 s.insert(y);
             }
             if(pow >= odd){
                cout<<"0\n";
                continue;
             }
             odd = odd - pow;
            auto it = s.rbegin();
           int flag = 0;
           int count  = 0;
           for(it = s.rbegin(); it != s.rend();it++){
           odd = odd - (*it);
            count++;
            if(odd <= 0){
                flag = 1;
                break;
            }
           }
           if(flag == 1){
            cout<<count<<endl;
           }
           else{
            cout<<"-1\n";
           }
    }
    return 0;
}