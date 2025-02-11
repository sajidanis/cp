// Problem Link -> https://codeforces.com/problemset/problem/768/C
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

void solve() {
    ll n, k, x;
    cin >> n >> k >> x;

    ll t;
    vi freq(1100, 0);

    loop(i, 0, n){
        cin >> t;
        freq[t]++;
    }

    while(k--){
        vi temp(freq.begin(), freq.end());
        int parity = 0;
        for(int i = 0 ; i < 1100 ; i++){
            if(freq[i] > 0){
                int y = i ^ x;
                int change = freq[i] / 2;
                if(parity == 0){
                    change += (freq[i] & 1);
                }
                temp[i] -= change;
                temp[y] += change;
                parity = parity ^ (freq[i] & 1);
            }
        }
        freq = temp;
    }

    ll mi = inf, ma = -inf;
    loop(i, 0, 1100){
        if(freq[i] > 0){
            mi = min(mi, i);
            ma = max(ma, i);
        }
    }
    cout << ma << " " << mi;
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