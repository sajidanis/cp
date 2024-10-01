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

struct TrieNode{
    TrieNode *children[26] = {NULL};
    bool isTerminal = false;
    int sum = 0;
    int acv = 0;
};


struct Trie{
    TrieNode *root;

    Trie() {
        root = new TrieNode();       
    }

    int search(string key){
        TrieNode *curr = root;
        for(auto &ch : key){
            int idx = ch - 'a';
            if(curr->children[idx]){
                curr = curr->children[idx];
            } else {
                return 0;
            }
        }
        return curr->acv;
    }

    void insert(string key, int val) {
        TrieNode *curr = root;
        int old = search(key);
        int new_val = val - old;
        for(auto &ch : key){
            int idx = ch - 'a';
            curr->sum += new_val;
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isTerminal = true;
        curr->sum += new_val;
        curr->acv = val;
    }
    
    int sum(string prefix) {
        TrieNode *curr = root;
        for(auto &ch : prefix){
            int idx = ch - 'a';
            if(curr->children[idx]){
                curr = curr->children[idx];
            } else {
                return 0;
            }
        }
        return curr->sum;
    }

};

void solve() {
    Trie *trie = new Trie();
    trie->insert("apple", 3);
    cout << trie->sum("ap") << " ";
    trie->insert("app", 2);
    trie->insert("apple", 2);
    cout << trie->sum("ap") << " ";

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