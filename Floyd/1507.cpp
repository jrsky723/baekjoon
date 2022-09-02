#include <bits/stdc++.h>
using namespace std;

int d[22][22];
bool road[22][22];
int n;
bool isPossible = true;

void revFloyd() {
  for (int k = 1; k <= n; k++) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (k == i || i == j || j == k) continue;
        if (d[i][j] > d[i][k] + d[k][j]) {
          isPossible = false;
          return;
        }
        else if (d[i][j] == d[i][k] + d[k][j])
        road[i][j] = false;
      }
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  
  cin >> n;

  for (int i = 1; i <= n; i++) fill(road[i] + 1, road[i] + 1 + n, true);
    
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++) cin >> d[i][j];
  
  revFloyd();

  int ans = 0;
  for (int i = 1; i <= n; i++)
    for (int j = 1; j <= n; j++)
      if (road[i][j] == true) ans += d[i][j];

  ans /= 2;
  if (isPossible) cout << ans;
  else cout << -1;
}