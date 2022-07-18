#include <bits/stdc++.h>
using namespace std;

int D[1001][3];
int R[1001], G[1001], B[1001];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> R[i] >> G[i] >> B[i];
  D[1][0] = R[1];
  D[1][1] = G[1];
  D[1][2] = B[1];

  for (int i = 2; i <= n; i++) {
    D[i][0] = min(D[i - 1][1], D[i - 1][2]) + R[i];
    D[i][1] = min(D[i - 1][0], D[i - 1][2]) + G[i];
    D[i][2] = min(D[i - 1][0], D[i - 1][1]) + B[i];
  }
  cout << min({D[n][0], D[n][1], D[n][2]});
}