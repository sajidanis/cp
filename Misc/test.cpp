#include <bits/stdc++.h>
using namespace std;

// Function to check if allocation is possible with maxPages
bool isPossible(vector<int>& books, int students, int maxPages) {
    int studentCount = 1, currentSum = 0;
    
    for (int pages : books) {
        if (currentSum + pages > maxPages) {
            studentCount++;
            currentSum = pages;
            if (studentCount > students) {
                return false;
            }
        } else {
            currentSum += pages;
        }
    }
    return true;
}

// Function to find the minimum of the maximum pages allocated
int allocateBooks(vector<int>& books, int students) {
    if (students > books.size()) return -1; // Not enough books

    int low = *max_element(books.begin(), books.end());  // Minimum max pages
    int high = accumulate(books.begin(), books.end(), 0); // Maximum max pages
    int result = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (isPossible(books, students, mid)) {
            result = mid; // Update the result
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return result;
}

int findPages(int arr[], int n, int m) {
    vector<int> books(arr, arr + n);
    return allocateBooks(books, m);
}

int main() {
    int n, m;
    cin >> n >> m; // Number of books and students
    vector<int> books(n);
    
    for (int i = 0; i < n; i++) {
        cin >> books[i];
    }

    cout << allocateBooks(books, m) << endl;
    return 0;
}