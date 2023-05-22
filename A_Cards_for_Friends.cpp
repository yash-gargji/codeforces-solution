#include<iostream>
using namespace std;

int main(){
    int a;
    cin>>a;
    while(a--){
        long long int x,y,num;
        cin>>x>>y>>num;
        if(num == 1){
            cout<<"YES\n";
            continue;
        }
        long long int count = 1;
        while(x%2 != 1  || y%2 != 1){
                if(x%2 == 0){
                    x = x/2;
                    count = count*2;
                }
                else if(y%2 == 0){
                    y = y/2;
                    count = count*2;
                }
        }
        if(count >= num)
        {
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    return 0;
}