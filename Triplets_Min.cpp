  #include<bits/stdc++.h>
using namespace std;
 
 
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     int t;
     cin>>t;
     
     while(t--){
        long long int n;
         cin>>n;
            long long int k;
            cin>>k;
         long long int arr[n];
           for(int i = 0;i<n;i++){
            cin>>arr[i];
           }
           sort(arr,arr+n);
           vector<long long int>v;
           long long int num = 0;
           for(long long int i = 1;i<= n-2;i++){
               long long int h = (n-i)*(n-i-1)/2;
             num = num + h;
              v.push_back(num);
           }
           for(int i = 0;i<k;i++){
             long long int p;
              cin>>p;
              auto it = lower_bound(v.begin(),v.end(),p) - v.begin();
              if(it >= n-1){
                cout<<arr[n-1]<<endl;
              }
              else{
              cout<<arr[it]<<endl;
              }
           }
     }
     return 0;
}