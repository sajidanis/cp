// Problem Link -> https://www.desiqna.in/16981/flipkart-sde-coding-oa-questions-and-solutions-set-22
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

bool check(int t, int m, vector<int> &apis){
    int total_time = 0;
    for(auto &el : apis){
        total_time += min(t, el);
    }

    return total_time >= m * t;
}


void solve() {
    int n;
    cin >> n;
    vector<int> apis(n);

    for(int i = 0 ; i < n ; i++){
        cin >> apis[i];
    }

    int m;
    cin >> m;

    int lo = 0;
    int hi = accumulate(apis.begin(), apis.end(), 0);
    int ans = 0;
    while(lo <= hi){
        int mid = lo + (hi - lo) / 2;
        if(check(mid, m, apis)){
            lo = mid+1;
            ans = mid;
        } else {
            hi = mid - 1;
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