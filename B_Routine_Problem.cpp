#include <bits/stdc++.h>
using namespace std;

int main() {
    long long int w, x, y, z;
    cin >> w >> x >> y >> z;
    long long int best_a = -1, best_b = -1;
    double best_factor = DBL_MAX; 

    for (int i = 1; i <= 1000; i++) {
        long long int scaled_w = w * i;
        long long int scaled_x = x * i;
        for (long long int num = 1; num * y <= scaled_w && num * z <= scaled_x; num++) {
            long long int b = num * y;
            long long int h = num * z;
            long long rem = (scaled_w - b) * scaled_x + (scaled_x - h) * b;

            if (rem == 0) {
                best_a = 0;
                best_b = 1;
                best_factor = 0.0;
                break;
            }

            double k = static_cast<double>(rem) / (scaled_w * scaled_x);
            if (k < best_factor) {
                best_a = rem;
                best_b = scaled_w * scaled_x;
                best_factor = k;
            }
        }

        if (best_factor == 0.0) {
            break;
        }
    }

    if (best_a != -1 && best_b != -1) {
        long long gcd = __gcd(best_a, best_b);
        best_a /= gcd;
        best_b /= gcd;
        cout << best_a << "/" << best_b << endl;
    } else {
        cout << "1/INF" << endl;
    }

    return 0;
}
