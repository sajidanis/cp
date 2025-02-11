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
#define log(args...) 	{ string _s = #args; replace(_s.begin(), _s.end(), ',', ' '); stringstream _ss(_s); istream_iterator<string> _it(_ss); err(_it, args); }
#define logarr(arr,a,b)	for(int z=(a);z<=(b);z++) cout<<(arr[z])<<" ";cout<<endl;	
#define token(str,ch)	(std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;)
vs tokenizer(string str,char ch) {std::istringstream var((str)); vs v; string t; while(getline((var), t, (ch))) {v.pb(t);} return v;}

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

vi fw_lis(vi &arr, ll n){
    vi dp(n+1, 1);
    dp[0] = 1;
    loop(i, 1, n){
        loop_rev(j, i-1, -1){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            } 
        }
    }
    return dp;
}

vi bw_lis(vi &arr, ll n){
    vi dp(n+1, 1);
    dp[n-1] = 1;
    loop_rev(i, n-2, -1){
        loop(j, i+1, n){
            if(arr[i] > arr[j]){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return dp;
}

void solve() {
    ll n;
    cin >> n;

    vi arr(n);

    loop(i, 0, n){
        cin >> arr[i];
    }

    auto fw = fw_lis(arr, n);
    auto bw = bw_lis(arr, n);

    logarr(fw, 0, n);
    logarr(bw, 0, n)

    ll res = 0;
    loop(i, 0, n){
        if(fw[i] <= 1 || bw[i] <= 1){
            continue;
        }
        res = max(res, fw[i] + bw[i] - 1);
    }
    cout << res;
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