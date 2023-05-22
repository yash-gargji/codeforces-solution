 #include<bits/stdc++.h>
using namespace std;

int main(){
   unsigned long long int a;
    cin>>a;
    if(a == 0){
     cout<<"1";
     return 0;
    }
     unsigned long long int sum = a*6 + 1;
      unsigned long long int num = 6*(a*(a-1))/2;
    cout<<sum + num;
    return 0;
}