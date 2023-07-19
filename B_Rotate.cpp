  #include<bits/stdc++.h>
 using namespace std;
 
 int main() {
       
              int n;
                cin>>n;
                string s[n];
                for(int i = 0;i<n;i++){
                    cin>>s[i];
                }
               
                 int arr[n][n];
                for(int i = 0;i<n;i++){
                  
                    for(int j = 0;j<n;j++){   
                       arr[i][j]  = s[i][j] - 48;
                }
                }
                int k;
                int num  = arr[0][0];
                for(int i  = 1;i<n;i++){
                     
                     k  = arr[0][i];
                      arr[0][i] = num;
                     num = k;
                }
                cout<<endl;
                for(int i  = 1;i<n;i++){
                       
                      int k  = arr[i][n-1];
                       
                      arr[i][n-1] = num;
                     num = k;
                }
                 for(int i  = n-2;i>=0;i--){
                      int k  = arr[n-1][i];
                      arr[n-1][i] = num;
                     num = k;
                }
                   for(int i = n-2;i>=0;i--){
                      int k  = arr[i][0];
                      arr[i][0] = num;
                     num = k;
                }
                for(int i = 0;i<n;i++){
                    for(int j = 0;j<n;j++){
                        cout<<arr[i][j];
                    }
                    cout<<endl;
                }
                 
       return 0;
 }