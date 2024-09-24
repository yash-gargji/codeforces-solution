#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;

    while(t--){
        int  n;
        cin>>n;
        string s = "aeiou";
        int ind = 0;
        int num = n / 5;
        int mod = n % 5;
        

        for(int i = 0 ;i<5;i++){
            int k = num;
            if(mod > 0){
                k++;
                mod--;
            }
            while(k--){
               cout<<s[i];
            }
        }
       cout<<endl;
    }
}