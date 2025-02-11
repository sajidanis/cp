// Problem Link ->
/* Md Sajid Anis */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll              long long int
#define ld              long double
#define mod             1000000007
#define inf             1e18
#define endl            "\n"
#define pb              emplace_back
#define vi              vector<ll>
#define vs              vector<string>
#define pii             pair<ll,ll>
#define ump             unordered_map
#define mp              map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff              first
#define ss              second
#define loop(var, start, end) for(ll var = start; var < end; var++)
#define loop_rev(var, start, end) for(ll var = start; var > end; var--)

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

int minimumGroups(int n, vi& ownership, int k) {
    // Prefix sums for Bob and Alice
    vector<int> prefixBob(n + 1, 0), prefixAlice(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefixBob[i + 1] = prefixBob[i] + (ownership[i] == 1 ? 1 : 0);
        prefixAlice[i + 1] = prefixAlice[i] + (ownership[i] == 0 ? 1 : 0);
    }

    // Function to calculate scores for a given number of groups
    auto calculateScores = [&](int m) {
        int groupSize = n / m;          // Size of each group
        int extra = n % m;             // Extra fishes distributed among first 'extra' groups
        int bobScore = 0, aliceScore = 0;

        int start = 0;                 // Start of current group
        for (int groupIndex = 0; groupIndex < m; groupIndex++) {
            int end = start + groupSize + (groupIndex < extra ? 1 : 0);
            int groupValue = groupIndex; // Group value = i - 1

            // Add score contributions for this group
            bobScore += groupValue * (prefixBob[end] - prefixBob[start]);
            aliceScore += groupValue * (prefixAlice[end] - prefixAlice[start]);

            start = end;  // Move to the next group
        }

        return make_pair(bobScore, aliceScore);
    };

    // Binary search for the minimum number of groups
    int left = 1, right = n;
    int result = -1;

    while (left <= right) {
        int mid = (left + right) / 2;
        auto [bobScore, aliceScore] = calculateScores(mid);

        if (bobScore - aliceScore >= k) {
            result = mid;      // Update result
            right = mid - 1;   // Try smaller m
        } else {
            left = mid + 1;    // Increase m
        }
    }

    return result == -1 ? -1 : result; // Return -1 if impossible
}

void solve() {
    ll n, k;
    cin >> n >> k;
    string fish;
    cin >> fish;

    vi fishes(n);

    for(int i = 0 ;i < n ; i++){
        fishes[i] = fish[i] - '0';
    }

    cout << minimumGroups(n, fishes, k);
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    cin >> t;
    while (t--) {
         solve();
         cout << "\n";
     }
#ifndef ONLINE_JUDGE
     clock_t end = clock();
     cerr << "\n[Executed In: " << double(end - begin) / CLOCKS_PER_SEC * 1000 << " ms]\n";
#endif
     return 0;
}