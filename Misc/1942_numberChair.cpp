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

static bool comp(vector<int> &a , vector<int> &b){
    return a[0] < b[0];
}

int smallestChair(vector<vector<int>>& times, int targetFriend) {
    
    auto target_time = times[targetFriend];

    times[targetFriend][1] = INT_MAX;

    sort(times.begin(), times.end(), comp);
    int chair = 0;  
    bool flag = false;
    for(int i = 0 ; i < times.size(); i++){
        flag = false;
        int curr_best = INT_MAX;
        int cur_j = 0;
        for(int j = 0; j < i; j++){
            if(times[i][0] >= times[j][1]){
                if(times[j][0] < curr_best){
                    curr_best = times[j][0];
                    cur_j = j;
                }
                // times[i][0] = times[j][0];
                // times[j][1] = INT_MAX - 1;
                flag = true;
            }
        }
        if(!flag){
            times[i][0] = chair++;
        } else {
            times[i][0] = curr_best;
            times[cur_j][1] = INT_MAX - 1;
        }
        if(times[i][1] == INT_MAX){
            return times[i][0];
        }
    }
    return 0;
}

void solve() {

    vector<vector<int>> times = {
    {24710, 60469}, {25295, 76256}, {11088, 34742}, {92605, 97746}, {68272, 68682},
    {44286, 70033}, {88703, 92573}, {37394, 87075}, {47741, 73042}, {5603, 9454}, 
    {88970, 96339}, {62904, 98525}, {42743, 69814}, {28999, 80490}, {76263, 90116}, 
    {78042, 90721}, {27856, 69492}, {20067, 54704}, {72177, 81840}, {34951, 76201}, 
    {59089, 65862}, {61102, 76554}, {32726, 48272}, {57683, 99972}, {74537, 85162}, 
    {88161, 90916}, {50114, 88989}, {5170, 11173}, {87698, 90284}, {78856, 84320}, 
    {14517, 51015}, {30757, 54925}, {28234, 45768}, {73177, 89666}
};

    cout << smallestChair(times, 3);

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