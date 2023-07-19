 #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n>>x;
        if(x == n){
            cout<< n<<" ";
             
             for(int i = 1;i<n-1;i++){
                cout<<i+1<<" ";
             }
             cout<<"1 \n";
             
        }
        else if(n%x != 0){
            cout<<-1<<endl;
        }
       
        else {
              int arr[n+1];
              arr[1] = x;
              for(int i = 2;i<=n-1;i++){
                  arr[i] = i;
              }
              arr[n] = 1;
            
           while (x<n)  {
            for(int i = x*2;i <= n;i +=x)
            {
                if (n % i == 0) 
                {
                    arr[x] = i;
                    x = i;
                    break;
                }
            }
        }
               for(int i = 1;i <= n;i++){
                cout<<arr[i]<<" ";
               } 
               cout<<endl; 
        }
    }
    
}