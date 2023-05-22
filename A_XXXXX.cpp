#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        int arr[n];
          int sum = 0;
            for(int i = 0;i<n;i++){
                  cin>>arr[i];
                  sum = sum + arr[i];
            }
            if(sum%x != 0){
                cout<<n<<endl;
            }
            else{
                int count1 = 0;
                int count2 = 0;
                for(int i = 0;i<n;i++){
                    count1++;
                    if(arr[i]%x != 0){
                        break;
                    }
                }
                for(int i = n-1;i>=0 ; i--){
                       count2++;
                    if(arr[i]%x != 0){
                        break;
                    }
                }
                n = n - min(count1,count2);
                if(n == 0){
                    cout<<"-1\n";
                }
                else{
                    cout<<n<<endl;
                }
            }
    }
    return 0;
}