#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxApplesWithinRange(const vector<int>& weights, int K) {
    int n = weights.size();
    int max_count = 0;
    int left = 0;

    // Sort the weights to use the sliding window
    vector<int> sorted_weights = weights;
    sort(sorted_weights.begin(), sorted_weights.end());

    // Use a sliding window approach
    for (int right = 0; right < n; ++right) {
        // Keep the window within the allowed range K
        while (sorted_weights[right] - sorted_weights[left] > K) {
            left++;
        }
        // Calculate the size of the window
        max_count = max(max_count, right - left + 1);
    }

    return max_count;
}

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

int main() {
    file_i_o();
    int K, N;
    cin >> K >> N;

    vector<int> weights(N);
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    int result = maxApplesWithinRange(weights, K);
    cout << result << endl;

    return 0;
}
