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



int getSum(unordered_map<int, int>& count, int x) {
    auto cmp = [](pair<int, int> & p1, pair<int, int> & p2) {
        return p1.second > p2.second || p1.second == p2.second && p1.first > p2.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int> >, decltype(cmp)> pq(cmp);
    for(auto it : count) {
        pq.push(make_pair(it.first, it.second));
        if (pq.size() > x) {
            pq.pop();
        }
    }
    int res = 0;
    while (!pq.empty()) {
        auto it = pq.top();
        pq.pop();
        res += it.first * it.second;
    }
    return res;
}
vector<int> findXSum(vector<int>& nums, int k, int x) {
    unordered_map<int, int> count;
    int len = nums.size();
    int start = 0;
    while (start < k - 1) {
        count[nums[start++]]++;
    }
    vector<int> res;
    while (start < len) {
        count[nums[start]]++;
        res.push_back(getSum(count, x));
        start++;
        if(count[nums[start - k]]-- == 1) {
            count.erase(nums[start - k]);
        }
    }
    return res;
}

void solve() {
    vector<int> nums = {1, 1, 2, 2, 3, 4, 2, 3};
    int k = 6;
    int x = 2;

    findXSum(nums, k, x);
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    //cin >> t;
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