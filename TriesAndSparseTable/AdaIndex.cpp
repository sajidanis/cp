// Problem Link -> https://www.spoj.com/problems/ADAINDEX/
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

struct TrieNode {
    TrieNode* children[26] = {NULL};
    size_t count = 0;
};

struct Trie{
    TrieNode *root;

    Trie() : root(new TrieNode) {}

    void insert(string str){
        TrieNode *curr = this->root;

        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode;
            }
            curr = curr->children[idx];
            curr->count++;
        }
       
    }

    ll findAllWords(string str){
        TrieNode *curr = this->root;
        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            int idx = ch - 'a';
            if(curr->children[idx] != NULL){
                curr = curr->children[idx];
            } else {
                return {};
            }
        }

        return curr->count;
    }
};

void solve() {
    ll n, m;
    cin >> n >> m;
    Trie trie;
    while(n--){
        string str;
        cin >> str;
        trie.insert(str);
    }

    while(m--){
        string str;
        cin >> str;
        cout << trie.findAllWords(str)<< "\n";
        // for(auto &el : trie.findAllWords(str)){
        //     cout << el << " ";
        // }
        // cout << "\n";
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