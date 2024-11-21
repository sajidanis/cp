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
    int dp[100005];

    int ms(int i, int n, int ans, vector<int>& nums1, vector<int> &nums2){
        if(i > 1 and (nums1[i-1] <= nums1[i-2] || nums2[i-1] <= nums2[i-2])){
            return 1e9;
        }
        if(i == n){
            return ans;
        }

        if(dp[i] != 1e9){
            return dp[i];
        }

        int nosw = ms(i+1, n, ans, nums1, nums2);

        swap(nums1[i], nums2[i]);
        int sw = ms(i+1, n, ans+1, nums1, nums2);
        swap(nums1[i], nums2[i]);
        

        return dp[i] = min(sw, nosw);
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        for(int i = 0 ; i <= nums1.size() ; i++){
            dp[i] = 1e9;
        }
        return ms(0, nums1.size(), 0, nums1, nums2);
    }

void solve() {
    vector<int> nums1 = {0, 4, 4, 5, 9};
    vector<int> nums2 = {0, 1, 6, 8, 10};
    cout << minSwap(nums1, nums2);
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