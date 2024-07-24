// Problem Link ->
/* Md Sajid Anis */
#include<bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
using namespace std;
#define ll 			 long long int
#define ld 			 long double
#define mod             1000000007
#define inf             1e18
#define endl 			 "\n"
#define pb 			 emplace_back
#define vi              vector<ll>
#define vs 			 vector<string>
#define pii             pair<ll,ll>
#define ump 			 unordered_map
#define mp 			 map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 			 first
#define ss 			 second
#define loop(var, start, end) for(ll var = start; var < end; var++)
#define loop_rev(var, start, end) for(ll var = start; var > end; var--)

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) { 
    for(auto &el : v){
        os << el << "";
    }
    return os; 
}

void file_i_o()
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("./input", "r", stdin);
    freopen("./output", "w", stdout);
#endif
}

vs get_subseq(string s){
    if(s.length() == 1){
        return {s};
    }
    vs prev_ans = get_subseq(s.substr(1));

    // self work
    vs ans;
    string ch = s.substr(0, 1);
    ans.push_back(ch);
    for(auto &el : prev_ans){
        ans.push_back(el);
        ans.push_back(ch+el); // String concatanation is expensive
    }
    return ans;
}

std::vector<char> v;
vector< vector<char> > result;

void subsequence(std::string &str, ll i){
    if(i == str.size()){
        result.push_back(v);
        return;
    }

    char ch = str[i];
    v.push_back(ch);
    subsequence(str, i+1);
    v.pop_back();
    subsequence(str, i+1);
}


bool myComparator(string s1, string s2){
    return s1.length() < s2.length();
}

void solve() {
    string s;
    cin >> s;
    v.reserve(s.size());
    result.reserve(1 << (s.size()));

    subsequence(s, 0);

    // vs subseq = get_subseq(s);
    // sort(subseq.begin(), subseq.end(), myComparator);
    for(auto &el : result){
        cout << el << "\n";
    }
}

int main(int argc, char const *argv[]) {
    clock_t begin = clock();
    file_i_o();
    ll t = 1;
    // cin >> t;
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