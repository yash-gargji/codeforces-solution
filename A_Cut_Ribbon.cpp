 #include<bits/stdc++.h>
using namespace std;

int main(){
    int num,a,b,c;
    
    cin>>num>>a>>b>>c;

     int min1 = min(a,b);
     int min3 = min(min1,c);
    int x,y,z;

    if((num%min(b,c)) == 0){
        x = num/min(b,c);
    }
    else{
     int product1 = (num/min(b,c))*min(b,c);

     while(product1 >= 0){
             if((num - product1)%max(b,c) == 0){
                 x = (num - product1)/max(b,c) + product1/min(b,c);
                break;
             }
             product1--;
     }
    }
     if((num%min(a,c)) == 0){
        x = num/min(a,c);
    }
    else{
       int product2 = (num/min(c,a))*min(c,a);

     while(product2 >= 0){
             if((num - product2)%max(c,a) == 0){
                y = (num - product2)/max(c,a) + product2/min(c,a);
                break;
             }
             product2--;
     }
    }
     if((num%min(b,a)) == 0){
        x = num/min(b,a);
    }
    else{
       int product3 = (num/min(a,b))*min(a,b);

     while(product3 >= 0){
             if((num - product3)%max(a,b) == 0){
                z = (num - product3)/max(a,b) + product3/min(a,b);
                break;
             }
             product3--;
     }
    }

     int w = num/(a+b+c);
     int maxin1 = max(x,y);
     int maxin2 = max(w,z);
     cout<<max(maxin1,maxin2);
    return 0;

}