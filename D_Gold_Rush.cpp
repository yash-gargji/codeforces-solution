 #include<bits/stdc++.h>
using namespace std;

int main(){
ios_base::sync_with_stdio(false);
    cin.tie(NULL);

     int num;
    cin>>num;

    while (num--){
      int n, m;
      cin>>n>>m;
 
    if (n == m){
      cout << "YES\n";
       continue;
   }
      else if (n%3 != 0 || m > n){
     cout<<"NO\n";
      continue;
 } 
   set<int>s;
   s.insert(n);

   int flag = 0;

      while(s.size() > 0){ 
          auto it = s.begin();
         int a = (*it);
         s.erase(it);

       if (a == m){
       cout << "YES\n";
     flag = 1;
      break;
    }

     if (a%3 ==0 ){
       a= a/3;

      if(a == m || 2*a == m){
      cout << "YES\n";
       flag = 1;
      break;
      }
     if(a%3 == 0){
        s.insert(a);

       s.insert(2*a);
     }
     }
    }
       if(flag == 0){
       cout<<"NO\n";
    }
    }
  return 0;
}