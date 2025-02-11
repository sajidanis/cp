// Problem Link -> https://leetcode.com/problems/word-search-ii/description/
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

struct TrieNode{
    TrieNode *children[26] = {nullptr};
    bool isTerminal = false;
};

struct Trie{
    TrieNode *root = new TrieNode();

    void insert(string word){
        TrieNode *curr = root;

        for(auto &ch : word){
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr){
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
        }
        curr->isTerminal = true;
    }

    bool search(string word){
        TrieNode *curr = root;

        for(auto &ch : word){
            int idx = ch - 'a';
            if(curr->children[idx] == nullptr){
                return false;
            }
            curr = curr->children[idx];
        }
        return curr->isTerminal;
    }

};


int dirX[4] = {0, 1, -1, 0};
int dirY[4] = {1, 0, 0, -1};

unordered_map<int, char> nodeMappings;

vector<string> res;

vector<vector<bool>> visited;

Trie *trie;

bool isValid(int i, int j, int m, int n){
    return i >= 0 and j >= 0 and i < m and j < n and !visited[i][j];
}

void findSimilar(int i, int j, string curWord, vector<vector<char>> &board){
    if(trie->search(curWord)){
        res.push_back(curWord);
    }
    int m = board.size();
    int n = board[0].size();
    for(int d = 0 ; d < 4 ; d++){
        int new_i = i + dirX[d];
        int new_j = j + dirY[d];
        if(isValid(new_i, new_j, m, n)){
            visited[new_i][new_j] = true;
            findSimilar(new_i, new_j, curWord + board[new_i][new_j], board);
            visited[new_i][new_j] = false;
        }
    }

}

vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    // create a graph from the board
    int m = board.size();
    int n = board[0].size();

    visited.assign(m, vector<bool>(n, false));


    trie = new Trie();

    for(auto &word : words){
        trie->insert(word);
    }


    for(int i = 0 ; i < m ; i++){
        for(int j = 0 ; j < n ; j++){
            string cur;
            findSimilar(i, j, cur + board[i][j], board);
        }
    }
    
    return res;
}

void solve() {
    vector<vector<char>> board = {{'o','a','a','n'},{'e','t','a','e'},{'i','h','k','r'},{'i','f','l','v'}};

    vector<string> words = {"oath", "pea", "eat", "rain"};

    findWords(board, words);

    for(auto &r: res){
        cout << r << "\n";
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