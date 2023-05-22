#include<bits/stdc++.h>
using namespace std;

int main(){
long int a,b;
cin>>a>>b;
long int sum  = 0;
int arr[a];

for(int i  = 0;i<a;i++){
    cin>>arr[i];
    sum  = sum +arr[i];
}
if(sum <= b){
    cout<<a;
    return 0;
}
   long int win_sum = 0;
   long int main = 0;
   int count  = 0;
   int j = 0;
   for(int i = 0;i<a;i++){
       win_sum  = win_sum  + arr[i];
       if(win_sum <= b){
        count++;
        main = win_sum ;
       }
       else{
           if(win_sum  == 0){
            continue;
           }
           else{
            win_sum  = win_sum - arr[j];
            j++;
           }
       }
   }
   cout<<count;

}