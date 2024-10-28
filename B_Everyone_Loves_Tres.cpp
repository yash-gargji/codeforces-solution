#include <iostream>
#include <string>
using namespace std;

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        if (n == 1 || n == 3) {
            cout << "-1" << endl;
        }
         else if (n == 2) {
              cout << "66" << endl;
            } 
         else  if(n % 2 == 0){
                string result(n - 4, '3');   
                result += "3366";             
                cout << result << endl;
            }
          else {
               string result(n - 4, '3');   
                result += "6366";             
                cout << result << endl;
          }
        }
    
    return 0;
}
