 #include<bits/stdc++.h>
using namespace std;

int lis(vector < int >&nums) {
  vector < int >sub;
  for (int x: nums){
    if (sub.empty() || sub[sub.size() - 1] < x) {
      sub.push_back(x);  
    } 
    else{
      auto it = lower_bound(sub.begin(), sub.end(), x);       
         *it = x;
       }
  }
  return sub.size();
}

bool isprime(int n){

    if (n <= 1)
        return false;
 
    for (int i = 2; i <= sqrt(n); i++)
        if (n%i == 0)
            return false;
 
    return true;
}
int main(){
        int t;
         cin>>t;
         while(t--){
              int n;
              cin>>n;
              int arr[n];
              for(int i = 0;i<n;i++){
                cin>>arr[i];
              }
              if(n == 1){
                std::cout<<"1\n";
                continue;
              }

              vector<int>ans;
              for(int i = 1;i <n; i++){
                 vector<int>v;
                 if(isprime(i+1)){
                    int fact = i+1;
                     int k = i+1;
                     v.push_back(arr[0]);
                     while(k<=n){
                          v.push_back(arr[k-1]);
                          k = k+fact;
                     }
                    ans.push_back(lis(v));
                    v.clear();
                 }
              }
                
	        std::cout<<*max_element(ans.begin(),ans.end())<<endl;
         }
 
	return 0;
}