#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
 
int fact(int n);
 
int nCr(int n, int r){
    return fact(n) / (fact(r) * fact(n - r));
}

 int fact(int n){
      if(n==0)
      return 1;
    int res = 1;
    for (int i = 2; i <= n; i++)
        res = res * i;
    return res;
}
 
int main(){
      string s1,s2;
      cin>>s1>>s2;
        float  sum1 = 0,sum2 = 0;
        for(int i = 0;i<s1.size();i++){
            if(s1[i] == '+'){
                sum1++;
            }
            else{
                sum1--;
            }
        }
      int count = 0;
      for(int i = 0;i<s2.size();i++){
        if(s2[i] == '+'){
            sum2++;
        }
        else if(s2[i] == '?'){
            count++;
        }
        else{
            sum2--;
        }
      }
     
      int num = sum1 - sum2;
      num = abs(num);
      long long int t,p;
      if(num > count || (count%2 == 1 && num%2 == 0) || (count%2 == 0 && num%2 == 1)||(sum1 != sum2) && count == 0){
         t = 0;
         cout<<t;
      }
      else if((sum1 == sum2) && count == 0 ){
        cout<<"1.000000000000";
      }
      else {
         int r = num + (count - num)/2;
         p = nCr(count,r);
         t = pow(2,count);
         double ans = (double)p/t;
         printf("%.12f\n",ans);
         
      }
}