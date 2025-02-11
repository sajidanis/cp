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
    freopen("../../input", "r", stdin);
    freopen("../../output", "w", stdout);
#endif
}

void solve() {
    int N, Q;
    cin >> N >> Q;
    int l = 1;
    int r = 2;
    int ans = 0;
    while(Q--){
        char ch;
        int target;
        cin >> ch >> target;

        if(ch == 'L'){
            if(target == l) continue;
            if(target < l){
                if(r > l or r < target){
                    // counter clockwise
                    ans += (l - target);
                } else {
                    ans += N - (l - target);
                }
            } else {
                if(r > l and r < target){
                    // counter clockwise
                    ans += N - (target - l);
                } else {
                    ans += (target - l);
                }
            }
            l = target;
        } else {
            if(target == r) continue;
            if(target < r){
                if(l > r or l < target){
                    // counter clockwise
                    ans += (r - target);
                } else {
                    ans += N - (r - target);
                }
            } else {
                if(l > r and l < target){
                    // counter clockwise
                    ans += (target - r);
                } else {
                    ans += N - (target - r);
                }
            }
            r = target;
        }
    }
    cout << ans;
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