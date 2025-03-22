#include <bits/stdc++.h>
using namespace std;

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, q;
        cin >> n >> q;

        vector<long long> a(n);
        long long total_sum = 0;
        long long even_sum = 0, odd_sum = 0;
        int even_count = 0, odd_count = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            total_sum += a[i];
            if (a[i] % 2 == 0) {
                even_sum += a[i];
                even_count++;
            } else {
                odd_sum += a[i];
                odd_count++;
            }
        }

        for (int i = 0; i < q; ++i) {
            int type;
            long long x;
            cin >> type >> x;

            if (type == 0) {
                // Add x to all even elements
                total_sum += even_count * x;
                even_sum += even_count * x;

                // If x is odd, even numbers become odd
                if (x % 2 != 0) {
                    odd_sum += even_sum;
                    odd_count += even_count;
                    even_sum = 0;
                    even_count = 0;
                }
            } else {
                // Add x to all odd elements
                total_sum += odd_count * x;
                odd_sum += odd_count * x;

                // If x is odd, odd numbers become even
                if (x % 2 != 0) {
                    even_sum += odd_sum;
                    even_count += odd_count;
                    odd_sum = 0;
                    odd_count = 0;
                }
            }

            cout << total_sum << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
