#include <bits/stdc++.h>
using namespace std;

int board[21][21];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,ans = 0x7f7f7f7f;
  cin >> n;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
      cin >> board[i][j];

  vector<int> mask(n,1);
  fill(mask.begin(), mask.begin() + n/2, 0);
  do {
    int team[2] = {};
    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++)
        if (mask[i] == mask[j]) team[mask[i]] += board[i][j];
    int  dif = abs(team[0] - team[1]);
    ans = min(ans,dif);
  } while (next_permutation(mask.begin(), mask.end())); 
  cout << ans;
}