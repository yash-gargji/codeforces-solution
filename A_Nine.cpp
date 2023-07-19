 #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);
       
               int n,m;
               cin>>n>>m;
                  int a = n,b = m;
               if( ((a <= 3 && b <= 3) || (a>= 7 && b>= 7) ||((a<= 6 && b<= 6 ) && (a>= 4 && b>=4))) && abs(a-b) == 1 ){
                cout<<"Yes\n";
               }
               else{
                cout<<"No";
               }
       
 }