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

int getCount(long long ans, int w){
    if(w > ans) return 0;
    if(w == ans) return 1;
    float discrimant = sqrtf(1.0f + (8*ans / (float)w));
    float up = (discrimant - 1) / 2;
    return floor(up);
}

bool check(long long ans, int mountainHeight, vector<int> &workers){
    int ma = workers[workers.size() - 1];
    int x = getCount(ans, ma);
    int n = workers.size();
    int k = mountainHeight;
    if(x > 0){
        mountainHeight -= n*x;
        if(mountainHeight <= 0){
            return true;
        }
    }

    for(int i = 0 ; i < n; i++){
        k -= getCount(ans, workers[i]);
        if(k <= 0){
            return true;
        }
    }
    return false;
}

long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
    sort(workerTimes.begin(), workerTimes.end());
    int n = workerTimes.size();

    long long lo = 0;
    long long hi = 50;

    long long ans = -1;

    while(lo <= hi){
        long long mid = lo + (hi - lo) / 2 ;
        if(check(mid, mountainHeight, workerTimes)){
            hi = mid-1;
            ans = mid;
        } else {
            lo = mid + 1;
        }
    }

    return ans;

}

void solve() {
    ll k, n;
    cin >> k >> n;
    vector<int> workers(n);

    loop(i, 0, n){
        cin >> workers[i];
    }

    cout << minNumberOfSeconds(k, workers);
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