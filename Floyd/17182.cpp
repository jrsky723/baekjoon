#include <bits/stdc++.h>
using namespace std;

int d[12][12];
int nxt[12][12];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++) {
      cin >> d[i][j];
      nxt[i][j] = j;
    }
  
  for (int k = 0; k < n; k++) {
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (d[i][j] > d[i][k] + d[k][j]) {
          d[i][j] = d[i][k] + d[k][j];
          nxt[i][j] = nxt[i][k];
        }
      }
    }
  } 
  vector<int> order;
  for (int i = 0; i < n; i++) if(i != k) order.push_back(i);
  long long ans = 0x7f7f7f7f;;
  do {
    int cur = k;
    long long mn = 0;
    for(auto dest : order) {
      while(cur != dest) {
        mn += d[cur][nxt[cur][dest]];
        cur = nxt[cur][dest];
      }
    }
    ans = min(mn, ans);
  } while(next_permutation(order.begin(), order.end()));
  cout << ans;
}