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
        int k = 0;
        int count = 0;

        for(int i = 0;i<s.size();i++){
            if(s[i] == '1') count++;
            else if(s[i] == '0'){
                int num = 1;

                for(int j = i+1;j<s.size();j++){
                    if(s[j] == '0'){
                        num++;
                        i = j;
                    }
                    else {
                        break;
                    }
                }
               k = max(k,num);
            }
        }
       cout<<count+k<<endl;
    }
}