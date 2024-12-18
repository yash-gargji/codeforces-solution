#include<bits/stdc++.h>
using namespace std;

int main(){ 
   int t;
   cin>>t;

   while(t--){
      int w,b;
      cin>>w>>b;

      int low = 0;
      int high = sqrt(1ll*2*(w + b));
      
      while(low <= high){
        int mid = (low + high)/2;
        int num1 = w,num2 = b,num = mid;

        while(num > 0){
           if(num1 >= num)
              num1 -= num;
           else if(num2 >= num)
             num2 -= num;
           else
             break;
           num--;
        }
        if(num == 0){
            low = mid + 1;
        }
        else
         high = mid - 1;
      }
      cout<<max(low-1,0)<<endl;
   }
}