#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>  // for std::gcd (C++17)
#include <unordered_map>
using namespace std;

// Disjoint Set Union (Union-Find) structure
struct DSU {
    vector<int> parent;
    DSU(int n) : parent(n) {
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b)
            parent[b] = a;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> health(n);
    for (int i = 0; i < n; i++) {
        cin >> health[i];
    }
    
    // Create a sorted copy of the health values to represent the target order.
    vector<int> sorted = health;
    sort(sorted.begin(), sorted.end());
    
    // DSU to group indices that can be swapped (i.e. gcd > 1)
    DSU dsu(n);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            // If two health counts are not coprime, they can be swapped.
            if (__gcd(health[i], health[j]) > 1) {
                dsu.unite(i, j);
            }
        }
    }
    
    // Map from component representative to list of indices in that component.
    unordered_map<int, vector<int>> comp;
    for (int i = 0; i < n; i++) {
        comp[ dsu.find(i) ].push_back(i);
    }
    
    bool possible = true;
    // For each connected component, the multiset of numbers in the original positions must
    // equal the multiset of numbers in the target sorted order at those positions.
    for (auto &entry : comp) {
        vector<int> indices = entry.second;
        vector<int> curValues, targetValues;
        for (int idx : indices) {
            curValues.push_back(health[idx]);
            targetValues.push_back(sorted[idx]);
        }
        sort(curValues.begin(), curValues.end());
        sort(targetValues.begin(), targetValues.end());
        if (curValues != targetValues) {
            possible = false;
            break;
        }
    }
    
    cout << (possible ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}
