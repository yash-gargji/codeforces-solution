#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int x,y;
    unsigned long long int a,b,num,m,n;

    cin>>x>>y;
     
    num= (y - x%y);
    a = x/y;
    m = (a*(a-1))/2;
    m = m*num;
    num = (x%y);
    b = x/y+1;
    n = (b*(b-1))/2;
    n = n*num;
    
    cout<<m+n<<" ";

    x= x-y+1;
    num= (x*(x-1))/2;
    cout<<num;
    return 0;
}