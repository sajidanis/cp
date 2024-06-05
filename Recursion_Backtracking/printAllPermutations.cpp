// Problem Link -> Given a string, print all permutations of the given string recursively
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
#define vvi       vector<vector<ll>>
#define vvs       vector<vs>
#define vp         vector<pii>
#define pii             pair<ll,ll>
#define ump 			 unordered_map
#define mp 			 map
#define pq_max          priority_queue<ll>
#define pq_min          priority_queue<ll,vi,greater<ll> >
#define ff 			 first
#define ss 			 second
#define loop(var, start, end) for(ll var = start; var < end; var++)
#define loop_rev(var, start, end) for(ll var = start; var > end; var--)

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

vs util(string s){
    if(s.length() == 1){
        return { s }; 
    }

    vs res;

    for(int i = 0 ; i < s.length() ; i++){
        string t = s.substr(0, i) + s.substr(i+1);
        string c = s.substr(i,1);
        auto prev = util(t);
        for(auto &el : prev){
            if(find(res.begin(), res.end(), c+el) != res.end()){
                continue;
            }
            res.push_back(c + el);
        }
    }
    return res;
}

/**
 * T(n) = n(n + T(n-1) + (n-1)! * n)
 * (n-1)! * n -> Due to appending of string out + ch
 * n -> for creating ros due to substr function
*/

void getPerm(string s, string out){
    if(s.size() == 0){
        cout << out << "\n";
        return; 
    }
    bool visited[26] = {0};
    for(int i = 0 ; i < s.size() ; i++){
        char ch = s[i];
        if(!visited[ch - 'a']){
            visited[ch - 'a'] = true;
            string ros = s.substr(0, i) + s.substr(i+1);
            getPerm(ros, out+ch);
        } 
    }
}

/*
    Optimized Solution
*/

void permOp(string &str, int i){
    if(i == str.size() - 1){
        cout << str << "\n";
        return;
    }

    bool visited[26] = {0};

    for(int j = i ; j < str.size() ; j++){
        char ch = str[j];
        if(!visited[ch - 'a']){
            visited[ch - 'a'] = true;
            swap(str[j], str[i]);
            permOp(str, i+1);
            swap(str[j], str[i]);
        }
    }
}

void solve() {
    string s;
    cin >> s;
    // auto res = util(s);
    // for(auto &el : res){
    //     cout << el << "\n";
    // }
    // getPerm(s, "");
    permOp(s, 0);
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