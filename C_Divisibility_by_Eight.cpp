#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int arr[s.size()];
    for(int i = 0;i<s.size();i++){
        arr[i] = s[i] -48;
        if(s[i] == '0'){
            cout<<"YES\n0";
            return 0;
        }
        else if(s[i] == '8'){
            cout<<"YES\n8";
            return 0;
        }
    }
    for(int i = 0;i<s.size();i++){
        int num = arr[i]*10;
        
        for(int j = i+1;j<s.size();j++){
            if((num + arr[j])%8 == 0){
                cout<<"YES\n"<<arr[i]<<arr[j];
                return 0;
            }
            else{
              for(int k = j+1;k<s.size();k++){
                if((num*10 + 10*arr[j] + arr[k]) %8 == 0){
                    cout<<"YES\n"<<arr[i]<<arr[j]<<arr[k];
                    return 0;
                }
              }
            }
        }
    }
    cout<<"NO";
    return 0;
}