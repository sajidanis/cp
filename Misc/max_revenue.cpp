#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Event {
    int start_time, end_time, revenue;
    Event(int s, int e, int r) : start_time(s), end_time(e), revenue(r) {}
};

// Comparator function to sort events based on end_time
bool compareEvents(const Event &e1, const Event &e2) {
    return e1.end_time < e2.end_time;
}

// Binary search function to find the last non-conflicting event index
int findLastNonConflicting(const vector<Event> &events, int index) {
    int low = 0, high = index - 1;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (events[mid].end_time <= events[index].start_time) {
            if (mid == index - 1 || events[mid + 1].end_time > events[index].start_time)
                return mid;
            else
                low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

// Function to compute the maximum revenue achievable with non-overlapping events
int maxRevenue(vector<Event> &events) {
    if (events.empty()) return 0;
    
    // Sort events by end_time
    sort(events.begin(), events.end(), compareEvents);
    
    int n = events.size();
    vector<int> dp(n);
    dp[0] = events[0].revenue;
    
    for (int i = 1; i < n; i++) {
        int includeRevenue = events[i].revenue;
        int lastIndex = findLastNonConflicting(events, i);
        if (lastIndex != -1) {
            includeRevenue += dp[lastIndex];
        }
        dp[i] = max(dp[i - 1], includeRevenue);
    }
    
    return dp[n - 1];
}

int main() {
    int num_events;
    cin >> num_events;
    vector<Event> events;
    
    for (int i = 0; i < num_events; i++) {
        int start_time, end_time, revenue;
        cin >> start_time >> end_time >> revenue;
        events.emplace_back(start_time, end_time, revenue);
    }
    
    int result = maxRevenue(events);
    cout << result << endl;
    
    return 0;
}
