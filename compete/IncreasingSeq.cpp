#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    long ans = 0;
    cin >> n;
    vector<long> arr(n);
    for(int i = 0; i < n ; i++){
        cin >> arr[i];
        if(i == 0){
            ans = arr[i] == 1 ? 2 : 1;
            continue;
        }
        if(arr[i] != ans + 1){
            ans++;
            continue;
        }
        ans = arr[i] - 1 == ans ? arr[i] + 1 : arr[i] - 1;
    }

    cout << ans;
}

int main(){
    long t;
    cin >> t;
    while(t--){
        solve();
        cout << "\n";
    }
    return 0;
}
