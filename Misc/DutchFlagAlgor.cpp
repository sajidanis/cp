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

void sortColors(vector<int>& nums) {
    int l = 0;
    int r = nums.size() - 1;;
    int i = 0;

    while(nums[l] == 0){
        l++;
    }

    while(nums[r] == 2){
        r--;
    }
    i = l;
    while(i <= r){
        if(nums[i] == 0){
            swap(nums[i], nums[l]);
            l++;
        } else if(nums[i] == 2){
            swap(nums[i], nums[r]);
            r--;
        } else {
            i++;
            continue;
        }
        while(nums[l] == 0){
            l++;
        }
        i = l;
    }
}

void solve() {
    vector<int> arr = {2, 0, 1};
    sortColors(arr);
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