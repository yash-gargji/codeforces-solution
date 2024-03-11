#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        long long int psum[n];
        psum[0]=arr[0];
        for(int i=1;i<n;i++){
            psum[i]=psum[i-1]+arr[i];
        }

        int q;
        cin>>q;
        while(q--){
            int x,y;
            cin>>x>>y;
            int ind;
            if(x == 1){
               ind  = 0;
            }
            else {
                ind = psum[x-2];
            }
            auto it=lower_bound(psum,psum+n,y+ind) - psum;
            if (psum[it]==y+ind || it==n){
                cout<<min(n,it+1)<<" ";
            }
            else
            {
                int num=psum[it]-(y+ind);
                if(y+ind-psum[it-1]>=num){
                    cout<<it+1<<" ";
                }
                else {
                    if(it<x){
                        cout<<x<<" ";
                    }
                    else cout<<it<<" ";
                }
            }
        }
        cout<<endl;
    }
}