 #include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
          int t;
          cin>>t;
          while(t--){
              int n;
              cin>>n;
              pair<int,int>p[n];

              for(int i = 0;i<n;i++){
                   int num1,num2;
                   cin>>num1>>num2;
                   p[i] = {num1,num2};
              }
              int count = 0;
              sort(p,p+n);
              if()
              for(int i = n-1;i>= 0;i--){
                int num1 = p[i].first - p[i].second;
                count++;
                if(num1 <= 0){
                    break;
                }
                for(int j = i-1;j>= 0;j--){
                    i = j;
                    if(p[j].first == num1 ){
                        i++;
                        break;
                    }
                }
              }
              cout<<count<<endl;
          }
}