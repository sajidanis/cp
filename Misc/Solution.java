import java.util.*;

class Event {
    int start_time;
    int end_time;
    int revenue;

    Event(int start_time, int end_time, int revenue) {
        this.start_time = start_time;
        this.end_time = end_time;
        this.revenue = revenue;
    }
}

public class Solution {

    // Computes the maximum revenue achievable with non-overlapping events.
    static int maxRevenue(List<Event> events) {
        if (events == null || events.size() == 0) {
            return 0;
        }

        // Sort events by their end_time.
        Collections.sort(events, new Comparator<Event>() {
            public int compare(Event e1, Event e2) {
                return e1.end_time - e2.end_time;
            }
        });

        int n = events.size();
        int[] dp = new int[n];
        dp[0] = events.get(0).revenue;

        // Build the dp table where dp[i] represents the max revenue using events[0...i].
        for (int i = 1; i < n; i++) {
            // Revenue if the current event is included.
            int includeRevenue = events.get(i).revenue;
            int lastIndex = findLastNonConflicting(events, i);
            if (lastIndex != -1) {
                includeRevenue += dp[lastIndex];
            }
            // dp[i] is the max of including or excluding the current event.
            dp[i] = Math.max(dp[i - 1], includeRevenue);
        }
        return dp[n - 1];
    }

    // Helper function to find the index of the last event that does not conflict with events[i].
    // Returns -1 if there is no such event.
    private static int findLastNonConflicting(List<Event> events, int i) {
        int low = 0, high = i - 1;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (events.get(mid).end_time <= events.get(i).start_time) {
                if (mid == i - 1 || events.get(mid + 1).end_time > events.get(i).start_time) {
                    return mid;
                } else {
                    low = mid + 1;
                }
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int num_events = scanner.nextInt();
        List<Event> events = new ArrayList<>();
        
        for (int i = 0; i < num_events; i++) {
            int start_time = scanner.nextInt();
            int end_time = scanner.nextInt();
            int revenue = scanner.nextInt();
            events.add(new Event(start_time, end_time, revenue));
        }
        
        int result = maxRevenue(events);
        System.out.print("Maximum Revenue: " + result);
        scanner.close();
    }
}
