 #include<bits/stdc++.h>
 using namespace std;
 
 int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
     long int t;
     cin>>t;
     
     while(t--){
         long long int a;
         cin>>a;
         int arr[a];
         for(int i = 0;i<a;i++){
            cin>>arr[i];
         }
         int ans = 0;
         for(int i = 0;i<a;i++){
             
            if(arr[i] == 0){
                 int max1 = 0;
                for(int j = i;j<a;j++){
                    if(arr[j] == 0){
                        i = j;
                        max1++;
                    }
                    else{
                        break;
                    }
                }
                ans = max(max1,ans);
            }
         }
           cout<<ans<<endl;
     }
     return 0;
 }