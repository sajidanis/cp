#include <bits/stdc++.h>

using namespace std;

void solve(){
    long n;
    cin >> n;
    if( n < 7 || n == 9 ){
        cout << "NO";
        return;
    }
    if(n == 11){
        cout << "YES\n";
        cout << 2 << " " << 4  << " " << 5;
        return;
    }

    cout << "YES\n";

    long s1 = n - 5;
    long s2 = n - 6;
    if(s1 % 3 == 0){
        cout << 1 << " " << 5 << " " << n - 6;
    }else {
         cout << 1 << " " << 4 << " " << n - 5;
    }
}

void file_io(){
    std::ios_base::sync_with_stdio(false);
    #ifndef ONLINE_JUDGE

    freopen("input", "r", stdin);
    freopen("output", "w", stdout);
  
#endif
}

int main(){
    file_io();

    long t = 0;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
}