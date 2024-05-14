#include <iostream>
using namespace std;
 

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
          int f1 = 0,f2 = 0;

          if(c  > min(a,b) &&  c < max(a,b))
            f1 = 1;
          if(d  > min(a,b) &&  d < max(a,b))
            f2 = 1;
         
        if (f1 != f2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }

    return 0;
}
