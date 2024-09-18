// Problem Link -> https://www.spoj.com/problems/TRYCOMP/
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
    bool isTerminal;
    string best = "-1";
    size_t bc = 0;
};

struct Trie{
    TrieNode *root;

    Trie() : root(new TrieNode) {}

    ll insert(TrieNode *root, string str, int pos){
        if(pos >= str.size()){
            root->count++;
            if(root->best == "-1"){
                root->best = str;
                root->bc = root->count;
            }else if(root->bc == root->count and str < root->best){
            root->best = str;
            }else if(root->bc < root->count){
                root->best = str;
                root->bc = root->count;
            }
            return root->count;
        }
        char ch = str[pos];
        int idx = ch - 'a';
        if(root->children[idx] == NULL){
            root->children[idx] = new TrieNode;
        }
        
        auto cnt = insert(root->children[idx], str, pos+1);
        if(root->best == "-1"){
            root->best = str;
            root->bc = cnt;
        }else if(root->bc == cnt and str < root->best){
            root->best = str;
        }else if(root->bc < cnt){
            root->best = str;
            root->bc = cnt;
        }
        return cnt;
    }

    void add(string str){
        insert(root, str, 0);
    }

    void insert(string str){
        TrieNode *curr = this->root;

        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode;
            }
            curr = curr->children[idx];
        }
        curr->count++;
        curr->isTerminal = true;
    }

    void helper(TrieNode *root, string str, string out, string &cur_best, ll &cnt){
        if(root == NULL) {
            return;
        }
        if(root->count >= cnt) {
            if(root->count == cnt){
                string t = str + out;
                cur_best = t < cur_best ? t : cur_best;
            }else {
                cur_best = str + out;
                cnt = root->count;
            }
        }
        for(int i = 0 ; i < 26 ; i++){
            helper(root->children[i], str, out + (char)('a' + i), cur_best, cnt);
        }
    }

    pair<string, int> findAllWords(string str){
        TrieNode *curr = this->root;

        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            int idx = ch - 'a';
            if(curr->children[idx] != NULL){
                curr = curr->children[idx];
            } else {
                return {"", -1};
            }
        }
        ll cnt = 0;
        string cur_best = "";
        helper(curr, str, "", cur_best, cnt);

        return {cur_best, cnt};
    }

    pair<string, int> getBestCount(string str){
        TrieNode *curr = this->root;

        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            int idx = ch - 'a';
            if(curr->children[idx] != NULL){
                curr = curr->children[idx];
            } else {
                return {"", -1};
            }
        }
        return {curr->best, curr->bc};
    }
};

void solve() {
    ll n, m;
    cin >> n;
    Trie trie;
    while(n--){
        string str;
        cin >> str;
        trie.add(str);
    }

    cin >> m;

    while(m--){
        string str;
        cin >> str;
        auto res = trie.getBestCount(str);
        if(res.second == -1){
            cout << -1 << "\n";
            continue;
        }
        cout << res.first << " " << res.second << "\n";
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