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
int minOperations(int x , int y, int count, int &best_found){
    if(x == y){
        best_found = min(best_found, count);
        return count;
    }
    if(count > (best_found)){
        return 1e5;
    }

    int t1=INT_MAX, t2 =INT_MAX, t3 = INT_MAX, t4 = INT_MAX;
    if(x % 11 == 0){
        t1 = minOperations(x / 11, y, count + 1, best_found);
    }
    if(x % 5 == 0){
        t2 = minOperations(x / 5, y, count + 1, best_found);
    }
    if(x > y){
        t3 = minOperations(x - 1, y, count + 1, best_found);
    }
    t4 = minOperations(x + 1, y, count + 1, best_found);
    int a = min(t1, t2);
    int b = min(t3, t4);
    return min(a, b);
}

int minimumOperationsToMakeEqual(int x, int y) {
    if(y > x){
        return y - x;
    }
    int bf = INT_MAX;
    return minOperations(x, y, 0, bf);
}

void solve() {
    cout << minimumOperationsToMakeEqual(26, 1);
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