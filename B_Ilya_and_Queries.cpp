#include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    int arr[s.length()];
    arr[0] = 0;
    for(int i = 1;i<s.length();i++){
        if(s[i] == s[i-1]){
            arr[i] = 1 + arr[i-1];
        }
        else{
            arr[i] = arr[i-1];
        }
    }
    int a;
    cin>>a;
     
    for(int i = 0;i<a;i++){
      int x,y;
      cin>>x>>y;
      
      cout<<arr[y-1] - arr[x-1]<<"\n";
    }
    return 0;
}