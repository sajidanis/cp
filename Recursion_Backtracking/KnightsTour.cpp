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

bool isSafe(ll i, ll j, vector<vi> &b, ll n){
    return i >= 0 and j >= 0 and i < n and j < n and b[i][j] == -1;
}

int dirx[] = {2, 1, -2, -1, 2,  1, -2, -1};
int diry[] = {1, 2, 1,  2,  -1, -2, -1, -2};

bool tour(vector<vi> &b, ll n, ll i, ll j, ll c){
    if(c == n*n){
        return true;
    }

    for(int d = 0 ; d < 8 ; d++){
        if(isSafe(i+dirx[d], j+diry[d], b, n)){
            b[i+dirx[d]][j+diry[d]] = c;
            if(tour(b, n, i+dirx[d], j+diry[d], c+1)) return true;
            b[i+dirx[d]][j+diry[d]] = -1;
            
        }
    }
    return false;
}

void solve() {
    vector<vi> b(5, vi(5, -1));
    b[0][0] = 0;
    if(tour(b, 5, 0, 0, 1)){
        cout << "YES a tour\n";
        loop(i, 0, 5){
            loop(j, 0, 5){
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
    } else {
        cout << "Not a tour";
    }
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