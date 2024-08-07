#include <bits/stdc++.h>

using namespace std;

void findSubsets(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    dp[0][0] = true;

    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= target; ++j) {
            if (j < nums[i - 1]) {
                dp[i][j] = dp[i - 1][j];
            } else {
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - nums[i - 1]];
            }
        }
    }

    vector<vector<int>> result;

    function<void(int, int, vector<int>)> getSubsets = [&](int i, int j, vector<int> path) {
        if (j == 0) {
            result.push_back(path);
            return;
        }
        if (i == 0) return;

        if (dp[i - 1][j]) {
            getSubsets(i - 1, j, path);
        }
        if (j >= nums[i - 1] && dp[i - 1][j - nums[i - 1]]) {
            path.push_back(nums[i - 1]);
            getSubsets(i - 1, j - nums[i - 1], path);
        }
    };

    getSubsets(n, target, {});

    cout << "Subsets of [";
    for (int num : nums) cout << num << " ";
    cout << "] that sum to " << target << ":\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) cout << num << " ";
        cout << "]\n";
    }
}

int main() {
    vector<int> array = {3, 5, 2};
    int target_sum = 5;
    findSubsets(array, target_sum);
    return 0;
}
