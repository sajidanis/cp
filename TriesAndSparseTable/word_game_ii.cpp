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
    TrieNode* children[26] = {NULL};
    bool isTerminal = false;
    string str = "";
};

struct Trie{
    TrieNode *root;
    Trie() : root(new TrieNode()) {}

    void insert(string str){
        TrieNode *curr = root;
        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            int idx = ch - 'a';
            if(curr->children[idx] == NULL){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isTerminal = true;
        curr->str = str;
    }

    bool search(TrieNode *root, string word) {
        if(word == ""){
            return root->isTerminal;
        }
        TrieNode *curr = root;
        for(int j = 0 ; j < word.size(); j++){
            char ch = word[j];
            if(ch == '.'){
                for(int i = 0; i <26; i++){
                    if(curr->children[i]){
                        return search(curr->children[i], word.substr(j+1));
                    }
                }
            }
            int idx = ch - 'a';
            if(curr->children[idx]){
                curr = curr->children[idx];
            } else {
                return false;
            }
        }
        return curr->isTerminal;
    }

    vector<string> isSeperated(string str, unordered_map<string, vector<string>> &dp){
        if(str.empty()){
            return {""};
        }
        if(dp.count(str) > 0 ){
            return dp[str];
        } 

        TrieNode *curr = root;
        vector<string> ans;
        for(int i = 0 ; i < str.size() ; i++){
            char ch = str[i];
            int idx = ch - 'a';
            if(curr->children[idx]){
                curr = curr->children[idx];
            } else {
                break;
            }
            if(curr->isTerminal){
                auto temp_ans = isSeperated(str.substr(i+1), dp);
                for(auto &el : temp_ans){
                    if(!el.empty()){
                        ans.push_back(curr->str + " " + el);
                    } else {
                        ans.push_back(curr->str);
                    }
                }
            }
        }
        return dp[str] = ans;
    }

    vector<string> isSeperated(string str){
        unordered_map<string, vector<string>> dp;
        return isSeperated(str, dp);
    }
};

vector<string> wordBreak(string s, vector<string>& wordDict) {
    Trie *trie = new Trie();
    for(auto &word : wordDict){
        trie->insert(word);
    }
    return trie->isSeperated(s);
}

void solve() {
    ll n;
    string s;
    cin >> n >> s;
    vector<string> wordDict(n);

    loop(i, 0, n){
        cin >> wordDict[i];
    }

    auto t = wordBreak(s, wordDict);
    for(auto &el : t){
        cout << el << "\n";
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