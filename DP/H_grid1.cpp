#include <bits/stdc++.h>

using namespace std;

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

bool isValid(int i, int j, vector<vector<char>> &mat){
  return i>=0 and j >=0  and i < mat.size() and j < mat[0].size() and mat[i][j] != '#';
}

int mod = 1e9+7;

long long dp[1001][1001];

long long f(int i, int j, vector<vector<char>> &matrix){
  if(!isValid(i, j, matrix)) return 0;
  if(i == matrix.size() - 1 and j == matrix[0].size() - 1){
    return 1;
  }
  if(dp[i][j] != -1) return dp[i][j];
  int first = f(i, j+1, matrix);
  int second = f(i+1, j, matrix);
  
  return dp[i][j] = ((first + second) % mod); 
}

int main(){
    file_i_o();
  int n, m;
  cin >> m >> n;
  
  vector<vector<char>> matrix(m, vector<char>(n));
  memset(dp, -1, sizeof dp);
  for(int i = 0 ; i < m ; i++){
    for(int j = 0 ; j < n ; j++){
      cin >> matrix[i][j];
    }
  }
  cout << f(0, 0, matrix);
  return 0;
}