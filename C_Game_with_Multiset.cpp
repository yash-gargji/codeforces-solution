#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int>v(30);

    while(t--){
         int t,num;
         cin>>t>>num;  
            if(t == 1){
                v[num]++;
            }
            else{
                 if(num == 0){
                    cout<<"YES\n";
                    continue;
                 }
                vector<int>dup = v;
                   int i = 0;
                   int flag = 0;

                  while(num != 0){
                      int rem = num%2;
                       num = num >> 1;
                        if(rem == 1){
                             if(dup[i] >= 1){
                                dup[i]--;
                                 flag = 1;
                             }
                             else{
                                 flag = 0;
                                 int fact = 2;
                                 for(int j = i - 1;j >= 0;j--){
                                      int k = dup[j];
                                       dup[j] = dup[j] - min(dup[j],fact);
                                       fact = fact - min(fact,k);
                                        fact = fact*2;
                                        if(fact == 0){
                                            flag = 1;
                                            break;
                                        }
                                 }
                                 if(flag == 0){
                                    break;
                                 }
                             }
                        }
                        else{
                            flag = 1;
                        }
                     i++;
                  }
                if(flag == 0){
                    cout<<"NO\n";
                }
                else{
                    cout<<"YES\n";
                }
            }
    }
}