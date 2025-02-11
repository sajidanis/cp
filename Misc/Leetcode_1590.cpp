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

int minLengthSubarray(vector<int> &nums, long long s){
    int l = 0, r = 0;
    int ans = INT_MAX;
    long long curr_sum = nums[l];
    int n = nums.size();
    while(r < n){
        if(curr_sum == s){
            ans = min(ans, r-l + 1);
        }
        if(curr_sum < s){
            r++;
            if(r < n){
                curr_sum += nums[r];
            }
        } else {
            if(l < r){
                l++;
                curr_sum -= nums[l-1];
            } else{
                l++;r++;
                if(r < n){
                    curr_sum = nums[r];
                }
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}

int minSubarray(vector<int>& nums, int p) {
    long long total = accumulate(nums.begin(), nums.end(), 0LL);
    long long rem = total % p;
    if(rem == 0) return 0;

    unordered_map<int, int> m;
    m[0] = -1;

    int presum = 0;
    long long t = 0;
    int mi = INT_MAX;

    for(int i = 0 ; i < nums.size() ; i++){
        presum = (presum + nums[i]) % p;
        t = (presum - rem + p) % p;
        if(m.contains(t)){
            mi = min(mi, i - m[t]);
        }
        m[presum] = i;
    }
    return mi == INT_MAX ? -1 : mi;
}


void solve() {
    int n, p;
    cin >> n >> p;
    vector<int> nums(n);
    loop(i, 0, n){
        cin >> nums[i];
    }
    cout << minSubarray(nums, p);
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