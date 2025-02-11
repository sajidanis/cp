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

int minLength(string s) {
    int l = 0, r = 1; 
    int n = s.size();
    bool mark[n];
    memset(mark, false, n * sizeof(bool));
    int count = 0;
    bool flag = false;
    while(true){
        flag = false;
        l = 0; 
        r = 1;
        while(r < n){
            while(mark[l]) l++;
            if(l >= n-1) break;
            r = l + 1;
            while(mark[r]) r++;
            if(r > n-1) break;
            if((s[l] == 'A' and s[r] == 'B') or (s[l] == 'C' and s[r] == 'D')){
                mark[l] = true;
                mark[r] = true;
                count += 2;
                flag = true;
            }
            l++;
            r++;
        }

        if(!flag or count == n){
            break;
        }
    }

    return n - count;

}

void solve() {
    cout << minLength("ABFCACDB");
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