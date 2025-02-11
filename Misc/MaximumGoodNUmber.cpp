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

string to_binary(int x){
    string res = "";
    while(x){
        res += (x & 1) ? '1' : '0';
        x >>= 1;
    }
    reverse(res.begin(), res.end());
    return res;
}

bool comp(string &s1, string &s2){
    return (s1 + s2 > s2 + s1);
}


int maxGoodNumber(vector<int>& nums) {
    vector<string> binaries;
    for(auto &el : nums){
        binaries.push_back(to_binary(el));
    }

    sort(binaries.begin(), binaries.end(), comp);

    string res = "";

    for(auto &el : binaries){
        res += el;
    }
    
    return stoi(res, nullptr, 2);
}

void solve() {
    vector<int> nums = {4, 2, 1};
    maxGoodNumber(nums);
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