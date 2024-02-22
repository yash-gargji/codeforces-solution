#include<bits/stdc++.h>
using namespace std;

long long dc(long long int n, int digit) {
    long long count = 0;
    long long p = 1;

    while (p <= n) {

        long long divisor = p * 10;
        count += (n / divisor) * p;
        count += min(max(n % divisor - digit * p + 1, 0LL), p);
        p *= 10;
    }
    return count;
}

long long sum(long long int n) {
    long long sum = 0;
    for (int digit = 1; digit <= 9; ++digit) {
        long long ds = digit * dc(n, digit);
        sum += ds;
    }
    return sum;
}

int main(){
    int t;
    cin>>t;
    
    while(t--){
        long long int  n;
        cin>>n;
        cout << sum(n) << endl;
    }
}