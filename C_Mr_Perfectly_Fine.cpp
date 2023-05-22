 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     long int t;
     cin>>t;
     
     while(t--){
         long long int a;
         cin>>a;
         int x = 0;
         int y = 0;
         int z = 0;
           int min1 = 0;
           int min2 = 0;
           int min3 = 0;
          
           for(int i = 0;i<a;i++){
            int w;
            cin>>w;
            string s;
            cin>>s;
            if(s[0] == '0' && s[1] == '0'){

                continue;
            }
            else if(s[0] == '1' && s[1] == '1'){
                if(z == 0){
                    z = 1;
                    min3 = w;
                    
                }
                else{
                    min3 = min(min3,w);
                }
            }
            else if(s[0] == '1'){
                 if(x == 0){
                    x = 1;
                    min1 = w;
                    
                }
                else{
                    min1 = min(min1,w);
                }
            }
            else{
                 if(y == 0){
                    y = 1;
                    min2 = w;
                }
                else{
                    min2 = min(min2,w);
                }
            }
           }
           if( x*y == 0 && z == 0){
            cout<<"-1\n";
           }
           else if(x*y == 0 && z == 1){
            cout<<min3<<endl;
           }
           else if(x*y == 1 && z == 1){
            cout<<min(min1+min2,min3)<<endl;
           }
           else{
            cout<<min1+min2<<endl;
           }

     }
     return 0;
 }