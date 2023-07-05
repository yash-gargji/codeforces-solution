#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         int arr[n];
         for(int i = 0;i<n;i++){
         cin>>arr[i];
        }
     int num1 = 0,num2 = 0;
      long long int s1 = 0,s2 = 0;
      int flag = 0;
      int f = -1;
      int r = n;
      int count = 0 ;
      while(1){
           if(count%2 == 0){
                if(f+1 >= r){
                    break;
                }
                else{
                    num1 = 0;
                    for(int i = f+1;i<r;i++){
                        
                        if(num1 > num2){
                            
                            break;
                        }
                        f = i;
                          s1 += arr[i];
                          num1 += arr[i];
                    }
                    count++;
                }
                 if(f+1 >= r){
                    break;
                }
           }
           else{
            if( r-1 <= f ){
                    break;
                }
                else{
                    num2 = 0;
                    for(int i = r-1;i>f;i--){
                        
                        if(num2 > num1){
                            break;
                        }
                        r = i;
                          s2 += arr[i];
                          num2 += arr[i];
                    }
                    count++;
                }
                 if(r-1 <= f){
                    break;
                }
           }
      }
      cout<<count<<" "<<s1<<" "<<s2<<endl;
    }
   return 0;
}