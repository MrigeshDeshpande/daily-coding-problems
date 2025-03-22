#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

struct DSU {
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n);
        size.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x != y) {
            if (size[x] < size[y]) swap(x, y);
            parent[y] = x;
            size[x] += size[y];
        }
    }

    int component_size(int x) {
        return size[find(x)];
    }
};

void solve() {
    int t;
    cin >> t;

    while (t--) {
        int n, c;
        cin >> n >> c;

        vector<pair<long long, int>> cities(n);
        for (int i = 0; i < n; i++) {
            cin >> cities[i].first; // population
            cities[i].second = i;  // index
        }

        // Sort cities by population (descending)
        sort(cities.rbegin(), cities.rend());

        DSU dsu(n);
        long long total_population = 0;

        bool possible = true;
        for (auto [pop, idx] : cities) {
            total_population += pop;

            // Check if we can connect the current node
            for (int i = 0; i < n; i++) {
                if (i == idx) continue;
                long long needed = 1LL * (idx + 1) * (i + 1) * c;
                if (total_population >= needed) {
                    dsu.unite(idx, i);
                } else {
                    possible = false;
                    break;
                }
            }

            if (possible && dsu.component_size(idx) == n) break;
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    return 0;
}
