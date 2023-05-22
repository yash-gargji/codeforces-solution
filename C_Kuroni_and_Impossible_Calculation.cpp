#include<bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int arr[a];
    set<int>s;

    for(int i =0;i<a;i++){
        cin>>arr[i];
        s.insert(arr[i]);
    }
    if(s.size() != a){
        cout<<0;
        return 0;
    }
    unsigned long long int sum = 1;
     for(int i = 0;i<a-1;i++){
        for(int j = i+1;j<a;j++){
            long int x = abs(arr[j] - arr[i]);
            
            
                sum = sum*(x%b);
                if(sum == 0){
                    cout<<0;
                    return 0;
                }
        }
     }
     cout<<sum%b;
     return 0;
}