#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
          int arr[n];
        int count = 0;
        
        for(int i = 0;i<n;i++){
            cin>>arr[i];
            arr[i] = arr[i]%3;  
        }
        for(int i = 0;i<n-2;i++){
                int num1 = (arr[i] + arr[i+1] + arr[i+2])%3;
                if(i + 2 == n-1 ){
                     count = count + num1;
                     break;
                }
            int num2 = (arr[i+1] + arr[i+2] + arr[i+3])%3;
            if(i+2 == n-2){
               count += max(num1,num2);
               break;
            }
             int num3 = (arr[i+2] + arr[i+3] + arr[i+4])%3;
             if(num1 == 0 ){
                  continue;
             }
           else  if( num1 == num2 && num2 == num3){
                 arr[i+2] = arr[i+2] + num2;
                 count+= num2;
                 i = i+2;
             }
             else if(num2 == 0){
                   arr[i] += num1;
                 count+= num1;
                  
             }
             else if(num1 == 2 && (num2 == num3)){
                    arr[i+2] += 1;
                    i++;
                 count+= num1;
             }
             else if(num1 == 2 && num2 == 1){
                   arr[0] += num2;
                   arr[i+1] += num2;
                 count+= num1;
             }
             else if(num1 == num2){
                   arr[i+1] += num2;
                 count+= num2;
             }       
        }
        cout<<count<<endl;
        }
         
    }
