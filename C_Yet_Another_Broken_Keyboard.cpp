 #include<bits/stdc++.h>
using namespace std;

int main(){
     ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 long int x,y;
 cin>>x>>y;
  
  string s;
  cin>>s;
  if(y == 26){
              unsigned long long int count = x*(x+1);
  unsigned long long int num = x/2;
  cout<<num;
  return 0;
  }
  string str;
  for(int i = 0;i<y;i++){
    char c ;
    cin>>c;
    str = str + c;
   }
    unsigned long long int sum = 0;
  for(int i = 0;i<x;i++){
    int count = 0;
    for(int j = i;j<x;j++){
        i = j;
          char c = s[j];
          int flag = 0;
          for(int k = 0;k<y;k++){
                if(str[k] == c){
                    flag = 1;
                    break;
                }
          }
          if(flag == 0){
            break;
          }
          else{
            count++;
          }
    }
    unsigned long long int n = count*(count +1);
    unsigned long long int num = n/2;
    sum = sum + num;
  }
  cout<<sum;
}