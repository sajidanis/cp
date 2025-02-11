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

struct TrieNode {
    char data;
    bool isTerminal;
    ump<char, TrieNode*> children;

    TrieNode(char ch) : data(ch), isTerminal(false) { }
};

struct Trie {
    TrieNode *root;
    Trie() : root(new TrieNode('\0')) { }

    void insert(string str) {
        TrieNode *temp = this->root;
        loop(i, 0, str.size()){
            char ch = str[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            } else {
                TrieNode *n = new TrieNode(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->isTerminal = true;
        return;
    }

    bool search(string str){
        TrieNode *temp = this->root;
        loop(i, 0, str.size()){
            char ch = str[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            } else {
                return false;
            }
        }
        return temp->isTerminal == true;
    }

    void helperDFS(TrieNode *root, string str, string out){
        if(root == NULL){
            return;
        }
        if(root->isTerminal) {
            cout << str + out << " ";
        }
        for(auto ch : root->children){
            helperDFS(ch.second, str, out + ch.first);
        }
    }

    void printPrefix(string str){
        TrieNode *temp = this->root;
        loop(i, 0, str.size()){
            char ch = str[i];
            if(temp->children.count(ch)){
                temp = temp->children[ch];
            } else {
                cout << "Query string is not present as prefix\n";
                return;
            }
        }

        helperDFS(temp, str, "");
    }
};

void solve() {
    string str;
    int n;
    cin >> n;
    Trie trie;
    while(n--){
        cin >> str;
        trie.insert(str);
    }

    int q;
    cin >> q;
    while(q--){
        cin >> str;
        cout << ((trie.search(str) == true) ? "YES\n" : "NO\n");
    }
    int prefixes;
    cin >> prefixes;
    while(prefixes--){
        cin >> str;
        cout << "The prefixes are: ";
        trie.printPrefix(str);
        cout << "\n";
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