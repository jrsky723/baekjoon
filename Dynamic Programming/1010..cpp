#include <bits/stdc++.h>
using namespace std;
const int MAX = 30;
long long comb[32][32];
int n, m, t;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  for (int i = 0; i <= MAX; i++) comb[i][0] = 1;
  for (int i = 1; i <= MAX; i++) {
    for (int j = 1; j <= MAX; j++) {
      comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
    }
  }
  cin >> t;
  while(t--) {
    cin >> n >> m;
    cout << comb[m][n] <<'\n';
  }
}