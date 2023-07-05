#include<bits/stdc++.h>
using namespace std;

int main(){
    int m,n;
    std::cin>>m>>n;
    int arr1[m][n];
    int arr2[m][n];
     int f3 = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
            
                std::cin>>arr1[i][j];
                if(arr1[i][j] == 1){
                    f3 = 1;
                }
        }
    }
    
    for(int i = 0;i<m;i++){
        int f1 = 1,f2 = 1;
        for(int j = 0;j<n;j++){
            
               if(arr1[i][j] == 1){
                  for(int k = 0;k<n;k++){
                        f1 = f1*arr1[i][k];
                    }
                   for(int k = 0;k<m;k++){
                        f2 = f2*arr1[k][j];
                   }
                   if(!(f1 || f2)){
                    std::cout<<"NO";
                    return 0;
                   }
                   if(f1 == 1 && f2 == 1){
                    arr2[i][j] = 1;
                   }
                   else{
                       arr2[i][j] = 0;
                   }
                   f1 = 1,f2 = 1;
               }
               else{
                arr2[i][j] = 0;
               }  
        }
    }
    int f4 = 0;
    for(int i = 0;i<m;i++){
        for(int j = 0;j<m;j++){
                if(arr2[i][j] ==1){
                    f4 = 1;
                }
        }
    }
    if(f3 == 1 && f4 == 0){
        cout<<"NO";
        return 0;
    }
    std::cout<<"YES\n";
    for(int i = 0;i<m;i++){
        for(int j = 0;j<n;j++){
           std::cout<<arr2[i][j]<<" ";
        }
        std::cout<<endl;
    }
 return 0;
}