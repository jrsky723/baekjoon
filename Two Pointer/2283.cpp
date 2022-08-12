#include <bits/stdc++.h>
using namespace std;
const int MAX = 1000000;
int line[MAX + 5];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, k;
  cin >> n >> k;

  for (int i = 0; i < n; i++) {
    int st, en;
    cin >> st >> en;
    for (int i = st; i < en; i++) line[i]++;
  }
  int a = 0, b = 0, en = 0, tot = 0;
  for (int st = 0; st < MAX; st++) {
    while (en < MAX && tot < k) tot += line[en++];
    if (tot == k) {
      a = st, b = en;
      break;
    }
    tot -= line[st];
  }
  cout << a << ' ' << b;
}