#include<bits/stdc++.h>
using  namespace std;

int main(){
    int a;
    cin>>a;
    if(a == 1){
        int num;
        cin>>num;
        cout<<num;
        return 0;
    }
    int arr[a];
      if(a%2 == 0){
        for(int i = 0;i<a;i++){
            cin>>arr[i];
            if(arr[i] < 0){
                cout<<arr[i] <<" ";
            }
            else{
                cout<< -1*(arr[i]) - 1<<" ";
            }
        }
        return 0;
      }
      else{
         int min1 = 10000000;
          map<int,int>m;
          m[-1] = 0;
          multiset<int>s1;
          multiset<int>s2;
          int p = 0;
         for(int i = 0;i<a;i++){

            cin>>arr[i];
            if(arr[i] == 0){
                arr[i] = -1;
            }  
             m[arr[i]]++;
             if(arr[i] < min1 && arr[i] > 0){
                  min1 = arr[i];
                  p = i;
             }
            if(arr[i]%2 == 1){
                    s1.insert(arr[i]);
            }
            else{
                s2.insert(arr[i]);
            }
         }
         if(s1.size() == a){
            if(m[-1] == a){
                for(int i = 0;i< a;i++){
                   cout<<"0 ";
                }
                return 0;
            }
            int num = -100000000;
            auto it = s1.rbegin();
            for(it = s1.rbegin() ;it != s1.rend() ;it++){
                     if((*it) != -1){
                         num = (*it);
                         break;
                     }
            }
                int y = 0;
                for(int i = 0;i<a;i++){
                         if(arr[i] == num && y == 0){
                                cout<< -arr[i] -1 <<" ";
                                y = 1;
                         }
                         else{
                         cout<<arr[i]<<" ";
                         }
                }  
         }
         else{
            if(s1.size() != 0){
            int m = *max_element(s1.begin(),s1.end());
            int n = *min_element(s2.begin(),s2.end());
              if(  -1*(m)> n ){
                int f = 0;
            for(int i = 0;i<a;i++){
                if(arr[i] == m && f == 0){
                    cout<<-arr[i]-1<<" ";
                    f = 1;  
                }
                else if(arr[i] > 0){
                    cout<<-arr[i] - 1 <<" ";
                }
                else{
                    cout<<arr[i] <<" ";
                }
            }
         }
         else{
            for(int i = 0;i<a;i++){
                if(i == p || arr[i] <0){
                    cout<<arr[i] <<" ";
                }
                else{
                    cout<<-arr[i] - 1<<" ";
                }
            }
         }
      }
         else{
              for(int i = 0;i<a;i++){
                if(i == p || arr[i] <0){
                    cout<<arr[i] <<" ";
                }
                else{
                    cout<<-arr[i] - 1<<" ";
                }
         }
      }
         }
      return 0;
}
}