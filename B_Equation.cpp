#include<bits/stdc++.h>
using namespace std;

int main(){
       double a,b,c;
       cin>>a>>b>>c;
       if(a == 0 && b == 0 && c == 0){
        cout<<"-1";
       }
       else if(a == 0 && b != 0){
          cout<<"1\n";
          cout << fixed << setprecision(15) <<-c/b;
       }
       else if(b*b - 4*a*c < 0 || (a == 0 && b == 0)){
        cout<<0;
       }
       else if(b*b - 4*a*c == 0){
        cout<<"1\n";
        cout << fixed << setprecision(15) << -b/(2*a);
       }
       else{
        cout<<"2\n";
        double num = (double)sqrt(b*b - 4*a*c);
           cout << fixed << setprecision(15) <<min((-b - num)/(2*a),(-b + num)/(2*a))<<endl;
           cout << fixed << setprecision( 15) << max((-b - num)/(2*a),(-b + num)/(2*a))<<endl;
       }
}