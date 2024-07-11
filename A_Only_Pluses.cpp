 #include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
         vector<int>v(3);
         cin>>v[0]>>v[1]>>v[2];

        for (int i = 0; i < 5; i++) {
            if (v[0] < v[1]) {
                if (v[0] < v[2])
                 v[0]++;
                else
                  v[2]++;
            } else {
                if (v[1] < v[2])
                v[1]++;
                else
                v[2]++;
            }
      }
      cout << v[0]*v[1]*v[2] << endl;
    }
}