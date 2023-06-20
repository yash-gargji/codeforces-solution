 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     int t;
     cin>>t;
     
     while(t--){
         int n;
         cin>>n;
         string s;
         cin>>s;
         char c = s[0];
          cout<<c;
          for(int i = 1;i<n;i++){
                 if(s[i] == c){
                       if(i == n-1){
                        break;
                       }
                       else{
                        c = s[i+1];
                        i++;
                            cout<<c;
                       }
                 }
          }
          cout<<endl;
     }
     
    return 0;
 }