#include<bits/stdc++.h>
using namespace std;
int removeDuplicates(int arr[], int n)
{
    // Return, if array is empty or 
    // contains a single element
    if (n == 0 || n == 1)
        return n;
 
    int temp[n];
 
    // Start traversing elements
    int j = 0;
   
    // If current element is not equal to next element
    // then store that current element
    for (int i = 0; i < n - 1; i++)
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];
 
    // Store the last element as whether it is unique or
    // repeated, it hasn't stored previously
    temp[j++] = arr[n - 1];
 
    // Modify original array
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];
 
    return j;
}
void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    n = removeDuplicates(arr, n);
    for(int i=n-1;i>0;i--){
        arr[i]-=arr[i-1];
    }
    for(int i=0;i<n;i++){
        if(arr[i]>1){
            n=i+1;
            break;
        }
    }
    if(n%2==1)cout<<"Alice\n";
    else cout<<"Bob\n";
}
int main(){
    int t;
    cin>>t;
    while(t--)
        solve();
}