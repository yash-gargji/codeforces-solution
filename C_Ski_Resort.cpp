 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
     int t;
     cin>>t;

     while(t--){
           long long int n,k,q;

           cin>>n>>k>>q;

            long long int sum = 0;
              int arr[n];

           for(int i =0;i<n;i++ ){
                  cin>>arr[i];
           }

           long int num = 0;

           for(int i = 0;i<n;i++){
                  for(int j = i;j<n;j++){
                    i = j;
                    if(arr[j] <= q){
                           num++;
                           
                    }
                    else{
                        break;
                    }
                  }
               
                   if(num >= k){
                       long long int p = num - k+ 1;
                       long long int product = (p*(p+1))/2;
                       sum = sum + product;
                                
                 }
                 num = 0;
           }
            cout<<sum<<endl;
     }
     
    return 0;
 }