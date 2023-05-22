 #include<bits/stdc++.h>
using namespace std;

 
int main(){
      ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin>>t;
    while(t--){
      int a;
     cin>>a;
    
    long long int sum = 0;
    multiset<int>s;
    
    for(int i = 0;i<a;i++){
       int x;
       cin>>x;
       if(x>0){
          s.insert(x);
       }
       else{
        if(s.size() == 0){
            continue;
        }
        else{
               auto it = s.end();
               it--;
              sum = sum + (*it);
               s.erase(it);
        }
     }
       
    } 
    cout<<sum<<endl;
    }
    return 0;
}