#include<bits/stdc++.h>
using namespace std;

 int decToBinary(int n){
      int count  = 0;
    
    while (n > 0) {
        count = count + n % 2;
        n = n / 2;
    } 
    return count ;
}

int main(){
    int n,m,k;
    cin>>n>>m>>k;
    int arr[m+1];

    for(int i = 0;i<= m;i++){
        cin>>arr[i];
    }
    int count = 0 ;
   long long int k1 = arr[m];

   for(int i = 0;i<m;i++){
      long long int num = k1^arr[i];
      int h = decToBinary(num);

      if(h <= k){
            count++;
      }
   }
   cout<<count;
   return 0;
}