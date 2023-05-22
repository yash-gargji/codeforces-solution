#include<bits/stdc++.h>
using namespace std;

int main(){
    int a;
    cin>>a;

    int arr[a];
    int x,y1;
    for (int i = 0;i<a;i++){
        cin>>arr[i];
    }
    if(a == 1){
        cout<<"yes\n";
        cout<<arr[0]<<" "<<arr[0];
        return 0;
    }
    
    int flag = 0;
    int f;
    int r;
    for(int i = 0;i<a-1;i++){
        if(arr[i] > arr[i+1]){
             f  = i;
            i = i+1;
             flag = 1;
             x = arr[f];
            
                int y = 0;
                for(int j = i+1;j<a;j++){
                    if(arr[j] < x ){
                          continue;
                    }
                    else{
                        r = j-1;
                        y = 1;
                        y1 = arr[r];
                        break;
                    }
                }
                if(y == 0){
                    r = a-1;
                    y1 = arr[a-1];
                }
                break;
        }
    }
    if(flag == 0){
        cout<<"yes\n";
        cout<<1<<" "<<1;
        return 0;
    }
    //  cout<<r<<f<<endl;
    int arr1[a];
    for(int i = 0;i<a;i++){
        if(i == f){
            for(int j = r; j>=f; j--){
                arr1[i] = arr[j];
                if(j != f){
                i++;
                }
            }
            
        }
        else{
            arr1[i] = arr[i];
        }
    }
    sort(arr,arr+a);
    for(int i = 0;i<a;i++){
        if(arr[i] != arr1[i]){
            flag =0;
            break;
        }
    }
    if(flag == 0){
        cout<<"no";
    }
    else{
        cout<<"yes\n";
       cout<<f+1<<" "<<r+1;
    }
    return 0;
  
}