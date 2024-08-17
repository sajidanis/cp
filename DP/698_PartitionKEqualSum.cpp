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
    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
#endif
}

void printAllSubset(int i, int j, vector<vector<int>> &dp, vector<int> &nums, vi path, vector<vi> &result, vector<bool> &visited){
    if(j == 0){
        result.push_back(path);
        for(auto &el : path){
            visited[el] = true;
        }
        return;
    }
    if(i == 0){
        return;
    }

    if(dp[i-1][j]){
        printAllSubset(i-1, j, dp, nums, path, result, visited);
    }
    if(nums[i-1] <= j and dp[i-1][j- nums[i-1]] and !visited[i-1]){
        path.push_back(i-1);
        printAllSubset(i-1, j-nums[i-1], dp, nums, path, result, visited);
    }
}

vector<vi> subsetSum(vector<int> &nums, vector<bool> &visited, int target){
    int n = nums.size();
    vector<vector<int>> dp(n+1, vector<int>(target+1, 0));

    dp[0][0] = 1;

    for(int i = 1; i <= n; i++){
        for(int j = 0 ; j <= target; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= nums[i-1]){
                dp[i][j] = dp[i-1][j] | dp[i-1][j - nums[i-1]];
            }
        }
    }

    vector<vi> result;

    if(dp[n][target]){
        printAllSubset(n, target, dp, nums, {}, result, visited);
        return result;
    }
    return {};
}


bool canPartitionKSubsets(vector<int>& nums, int k) {
    int total_sum = 0;
    int n = nums.size();
    sort(nums.begin(), nums.end(), greater<int>());
    for(int i = 0; i < n ; i++){
        total_sum += nums[i];
    }

    if(total_sum % k != 0){
        return false;
    }

    vector<bool> visited(n, false);
    int target = total_sum / k;

    auto res = subsetSum(nums, visited, target);
    cout << res.size() << "\n";
   
    for(auto &v : res){
        for(auto &el : v){
            cout << nums[el] << " ";
        }
        cout << "\n";
    }


    if(res.size() == k){
        return true;
    }
    return false;

}

void solve() {
    ll n, k;
    cin >> n >> k;

    vector<int> nums(n);

    loop(i, 0, n){
        cin >> nums[i];
    }

    cout << canPartitionKSubsets(nums, k);
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