#include <bits/stdc++.h>
using namespace std;

// Returns size of maximum sized subset and prints the subset elements
// if there is a subset of set[] with sum equal to the given sum.
// It returns -1 if there is no subset with the given sum.
int isSubsetSum(int set[], int n, int sum) {
    // The value of subset[i][j] will be true if there
    // is a subset of set[0..j-1] with sum equal to i
    bool subset[sum + 1][n + 1];
    int count[sum + 1][n + 1];

    // If sum is 0, then answer is true
    for (int i = 0; i <= n; i++) {
        subset[0][i] = true;
        count[0][i] = 0;
    }

    // If sum is not 0 and set is empty,
    // then answer is false
    for (int i = 1; i <= sum; i++) {
        subset[i][0] = false;
        count[i][0] = -1;
    }

    // Fill the subset table in bottom-up manner
    for (int i = 1; i <= sum; i++) {
        for (int j = 1; j <= n; j++) {
            subset[i][j] = subset[i][j - 1];
            count[i][j] = count[i][j - 1];
            if (i >= set[j - 1]) {
                subset[i][j] = subset[i][j] || subset[i - set[j - 1]][j - 1];
                if (subset[i][j]) {
                    count[i][j] = max(count[i][j - 1], count[i - set[j - 1]][j - 1] + 1);
                }
            }
        }
    }

    // If no subset with the given sum exists, return -1
    if (count[sum][n] == -1) {
        cout << "No subset with the given sum." << endl;
        return -1;
    }

    // Backtrack to find the elements that make up the sum
    int i = sum, j = n;
    vector<int> result;
    while (i > 0 && j > 0) {
        // If this element is included in the subset
        if (subset[i][j] && count[i][j] != count[i][j - 1]) {
            result.push_back(set[j - 1]);  // Add the element to the result
            i -= set[j - 1];               // Reduce the sum by this element
            j--;                           // Move to the previous item
        } else {
            j--;  // Move to the previous item if it's not included
        }
    }

    // Print the elements of the subset
    cout << "Subset with maximum size that sums to " << sum << ": ";
    for (int elem : result) {
        cout << elem << " ";
    }
    cout << endl;

    return count[sum][n];
}

// Driver code
int main() {
    int set[] = {2, 3, 5, 10, 7};
    int sum = 7;
    int n = sizeof(set) / sizeof(set[0]);
    int maxSize = isSubsetSum(set, n, sum);
    if (maxSize != -1) {
        cout << "Maximum number of elements in subset: " << maxSize << endl;
    }
    return 0;
}
