#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
          int a = 1;
          int b = 0;
          int sum1 = 0,sum2 = 0;
          for(int i = 0;i<n;i++){
            if(s[i] == 'A' && a == 1){
                b = 0;
                sum1++;
            }
            else if(s[i] == 'A' && a == 0){
                b = 0;
                a = 1;
            }
              else if(s[i] == 'B' && b == 0){
                a = 0;
                b = 1;
            }
              else if(s[i] == 'B' && b == 1){
                a = 0;
                sum2++;
            }
          }
          cout<<sum1<<" "<<sum2<<endl;
    }
}
