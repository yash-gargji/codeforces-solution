   #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
          int n;
          cin>>n;
          int arr[n];
          for(int i = 0;i<n;i++){
               cin>>arr[i];
          }
         
          int flag = 0;
          int count = 0;
          for(int i = 0;i<n;i++){
            int k  = i;
                 int num = arr[i];
                 int o ,p ;
                 int f1 = 0,f2 = 0;
                  while(1){
                    f1 = 0,f2 = 0;
                      for(int j = k-1;j >= 0;j--){
                            if(arr[j] > num){
                                f1 = 1;
                                o = j;
                                break;
                            }
                      }
                      for(int j = k+1;j <n;j++){
                            if(arr[j] > num){
                                f2 = 1;
                                p = j;
                                break;
                            }
                      }
                      if(f1 == 1 && f2 == 1){
                            count++;
                            flag = 1;
                            if(arr[o] > arr[p]){
                                k = p;
                                num = arr[p];
                            }
                            else{
                                k = o;
                                num = arr[o];
                            }
                            
                      }
                      else if(f1 == 1 && f2 == 0){
                            count++;
                            flag = 1;
                             num = arr[o];
                             k = o;
                      }
                      else if(f2 == 1 && f1 == 0){
                        count++;
                        flag = 1;
                        num = arr[p];
                        k = p;
                      }
                      else{
                          f1 = 0;
                          f2 = 0;
                        flag = 0;
                        break;
                      }
                  }
                  cout<<count<<" ";
                  count = 0;
          }
          cout<<endl;
    }
    return 0;
}