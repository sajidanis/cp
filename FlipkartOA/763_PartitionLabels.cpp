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

vector<int> partitionLabels(string s) {
    int last[26];
    fill(last, last + 26, -1);
    int n = s.size();

    for(int i = n-1 ; i >= 0 ; i--){
        int idx = s[i] - 'a';
        if(last[idx] == -1){
            last[idx] = i;
        }
    }

    vector<int> res;
    int currentPart = -1;
    int cnt = 0;
    for(int i = 0 ; i < n ; i++){
        int idx = s[i] - 'a';
        if(currentPart == -1){
            currentPart = last[idx];
        }
        cnt++;
        if(last[idx] > currentPart){
            currentPart = last[idx];
        }

        if(i == currentPart){
            res.push_back(cnt);
            cnt = 0;
            currentPart = -1;
        }
    }
    return res;        
}

void solve() {
    partitionLabels("ababcbacadefegdehijhklij");
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