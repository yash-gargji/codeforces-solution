#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         long long int n,k;
         cin>>n>>k;

         int arr[n];

         for(int i = 0;i<n;i++){
            cin>>arr[i];
         }
        int l = 0;
        int r = n-1;
        int count = 0;
        int flag = 0;
        long long sum1=(k+1)/2;
        long long sum2=k-sum1;
        int i;
        for( i=0;i<n;i++){
            if(sum1>=arr[i]){
                count++;
                sum1-=arr[i];
            }
            else {
                arr[i]-= sum1;
                break;
            }
        }
       // sum2 += sum1;
        for(int j=n-1;j>=i;j--){
            if(sum2>=arr[j]){
                count++;
                sum2-=arr[j];
            }
            else {
                break;
            }
        }
        cout<<count<<endl;
    }
}