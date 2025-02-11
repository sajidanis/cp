#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <bits/stdc++.h>
using namespace std;

void file_i_o()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("../input", "r", stdin);
    freopen("../output", "w", stdout);
#endif
}
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int countWaysI(int N, vector<int>& A) {
    int count = 0;

    // Loop over all possible triplets (p, q, r) with p < q < r
    for (int p = 0; p < N - 3; ++p) {
        for (int q = p + 1; q < N - 2; ++q) {
            for (int r = q + 1; r < N - 1; ++r) {
                // Calculate the required value for A[s] to satisfy the condition
                if (A[p] * A[r] % A[q] == 0) {  // Ensure integer division
                    int target = A[p] * A[r] / A[q];

                    for(int s = r + 1; s < N ; s++){
                        if(A[s] == target){
                            count++;
                        }
                    }
                }
            }
        }
    }

    return count;
}

int countWays(int n, vector<int> &A){
    int count = 0;
    map<pair<int, int>, int> mp;
    for(int r = 1; r < n ; r++){
        for(int s = r+1 ; s < n ; s++){
            int g = __gcd(A[r], A[s]), f1 = A[s] / g, f2 = A[r] / g;
            if(mp.find({f1, f2}) != mp.end()) count += mp[{f1, f2}];
        }

        for(int p = 0; p < r; p++){
            int g = __gcd(A[p], A[r]), f1 = A[p] / g, f2 = A[r] / g;
            mp[{f1, f2}]++;
        }
    }
    return count;
}

int countWaysIII(int N, vector<int>& A) {
    int count = 0;

    // Loop over all possible triplets (p, q, r) with p < q < r
    for (int p = 0; p < N - 3; ++p) {
        for (int q = p + 1; q < N - 2; ++q) {
            for (int r = q + 1; r < N - 1; ++r) {
                // Calculate the required value for A[s] to satisfy the condition
                if (A[p] * A[r] % A[q] == 0) {  // Ensure integer division
                    int target = A[p] * A[r] / A[q];

                    // Use a hash set to check if `target` exists after index r
                    unordered_set<int> seen(A.begin() + r + 1, A.end());
                    if (seen.find(target) != seen.end()) {
                        count++;
                    }
                }
            }
        }
    }

    return count;
}

int countWaysII(int N, vector<int>& A) {
    if (N < 4) return 0;  // Not enough elements to form a subsequence of length 4

    // Step 1: Precompute suffix sets
    vector<unordered_map<int, int>> suffix_sets(N, unordered_map<int, int>());
    
    suffix_sets[N-1][A[N-1]] = 1;

    for (int i = N - 2; i >= 0; --i) {
        suffix_sets[i] = suffix_sets[i + 1];  // Copy the next suffix map

        // Increment the frequency of A[i] in the current suffix map
        suffix_sets[i][A[i]]++;
    }

    int count = 0;

    // Step 2: Loop over all possible triplets (p, q, r)
    for (int p = 0; p < N - 3; ++p) {
        for (int q = p + 1; q < N - 2; ++q) {
            for (int r = q + 1; r < N - 1; ++r) {
                // Calculate the required value for A[s] to satisfy the condition
                if (A[p] * A[r] % A[q] == 0) {  // Ensure integer division
                    int target = A[p] * A[r] / A[q];

                    // Check if `target` exists in the suffix set starting from index r+1
                    if (suffix_sets[r + 1].find(target) != suffix_sets[r + 1].end()) {
                        count += suffix_sets[r + 1][target];  // Add the frequency of `target`
                    }
                }
            }
        }
    }

    return count;
}


int main() {
    file_i_o();
    int N = 5;
    vector<int> A = {1, 1, 2, 2, 1};
    
    cout << countWays(N, A) << endl;  // Expected output: 1
    return 0;
}
