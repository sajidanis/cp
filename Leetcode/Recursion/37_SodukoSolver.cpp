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
#define vc              vector<char>
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
bool isValid(ll r, ll c){
    return r >= 0 and c >= 0 and r < 9 and c < 9;
}

bool isSafe(char ch, ll r, ll c, vector<vc> &board) {
    if(!isValid(r, c)){
        return false;
    }
    // Check in row
    loop(i, 0, 9){
        if(board[r][i] == ch){
            return false;
        }
    }

    // Check in col
    loop(i, 0, 9){
        if(board[i][c] == ch){
            return false;
        }
    }

    // Check in a box

    ll R = (r / 3) * 3;
    ll C = (c / 3) * 3;

    loop(i, R, R + 3){
        loop(j, C, C + 3){
            if(board[i][j] == ch){
                return false;
            }
        }
    }

    return true;
}

bool check(vector<vc> &board){
    loop(i, 0, 9){
        loop(j, 0, 9){
            if(board[i][j] == '.'){
                return false;
            }
        }
    }
    return true;
}

void display(vector<vc> &board){
    loop(i, 0, 9){
        loop(j, 0, 9){
            cout << board[i][j] << ",";
        }
        cout << "\n";
    }
}

bool sodukoSolver(ll row, ll col, vector<vc> &board){
    if(col == 9){
        return sodukoSolver(row+1, 0, board);
    }

    if(row == 9){
        return true;
    }

    if(board[row][col] == '.'){
        for(ll num = 1 ; num <= 9 ; num++){
            char ch = '0' + num;
            if(isSafe(ch, row, col, board)){
                board[row][col] = ch;
                bool res = sodukoSolver(row, col+1, board);
                if(res) return true;
                board[row][col] = '.';
            }
        }
        return false;
    } else {
        return sodukoSolver(row, col+1, board);
    }
    
    // if(solved){
    //     return;
    // }
    // if(check(board)){
    //     display(board);
    //     solved = true;
    //     return;
    // }

    // for(ll sr = row ; sr < 9 ; sr++){
    //     for(ll sc = (sr == row) ? col : 0 ; sc < 9 ; sc++){
    //         for(ll i = 0 ; i < 9 ; i++){
    //             char ch = '1' + i;
    //             if(isSafe(ch, sr, sc, board)){
    //                 char temp = board[sr][sc];
    //                 board[sr][sc] = ch;
    //                 sodukoSolver(sr, sc, solved, board);
    //                 board[sr][sc] = temp;
    //             }
    //         }
    //     }
    // }
}

void solve() {
    vector<vc> board(9, vc(9, '.'));

    loop(i, 0, 9){
        loop(j, 0, 9){
            cin >> board[i][j];
        }
    }

    bool res = sodukoSolver(0, 0, board);
    if(res){
        display(board);
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