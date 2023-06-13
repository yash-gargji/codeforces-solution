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
         for(int i = 0;i<n;i++){
            cin>>arr[i];
         }
         vector<pair<long long int,long long int>>v1;
         vector<pair<long long int,long long int>>v2;

      for(int i = 1;i<= 1000000000;i++) {
        long long int sum = 0;
        for(int j = 0;j<n;j++){
                 sum = sum + abs(i - arr[i]);
        }
         if(i <= 499999){
            v1.push_back(make_pair(sum,i));
      }
      else{
            v2.push_back(make_pair(sum,i));
      }
      }
      sort(v1.begin(),v1.end());
      sort(v1.begin(),v1.end());
            

     }
     
    return 0;
 }