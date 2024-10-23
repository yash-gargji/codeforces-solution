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
        int o = 0;
        int z = 0;

        for(int i = 0;i<n;i++){
           if(s[i] == '1')
             o++;
            else 
             z++;
        }
        if(o == 0){
           cout<<n<<endl;
        }
        else if(o % 2)
          cout<<"1\n";
        else 
          cout<<"0\n";
    }
}