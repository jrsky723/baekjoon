#include <bits/stdc++.h>
using namespace std;

const int MAX = 500, INF = 0x3f3f3f3f;
int S[MAX + 5][MAX + 5];
int n;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  vector<int> C;
  for (int i = 0; i < n; i++) {
    int r, c;
    cin >> r >> c;
    if (i == 0) C.push_back(r);
    C.push_back(c);
  }
  for (int d = 1; d <= n - 1; d++) 
    for (int i = 1; i <= n - d; i++) {
      int j = i + d;
      S[i][j] = INF;
      for (int k = i; k <= j - 1; k++)
      S[i][j] = min(S[i][j], S[i][k] + S[k + 1][j] + C[i - 1]*C[k]*C[j]);
    }
  cout << S[1][n];
}