#include <bits/stdc++.h>
using namespace std;

const int MAX = 1000;
int n;
int W[1000];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> W[i];
  sort(W, W + n);
  int res = 1;
  for (int i = 0; i < n; i++) {
    if (W[i] > res) break;
    res += W[i];
  }
  cout << res;
}