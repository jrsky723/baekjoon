#include <bits/stdc++.h>
using namespace std;

const int MAX = 10000;
string cmd[10000];

int D(int n) {
  n = 2 * n % MAX;
  return n;
}

int S(int n) {
  n--;
  if (n < 0) n = MAX - 1;
  return n;
}
//rotate사용하지말고, int로 할 수 있으면 할 것
int L(int n) {
  int thousand = n / 1000;
  n -= thousand * 1000;
  n *= 10;
  n += thousand;
  return n;
}
int R(int n) {
  int digit = n % 10;
  n /= 10;
  n += digit * 1000;
  return n;
}

bool OOB(int x) { return x < 0 || x >= MAX; }

string bfs(int st, int tg) {
  string ret;
  fill(cmd, cmd + MAX, "0");
  queue<int> q;
  cmd[st] = "";
  q.push(st);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur == tg) {
      ret = cmd[cur];
      break;
    }
    for (char c : {'D', 'S', 'L', 'R'}) {
      int nxt = cur;
      if (c == 'D')
        nxt = D(cur);
      else if (c == 'S')
        nxt = S(cur);
      else if (c == 'L')
        nxt = L(cur);
      else
        nxt = R(cur);
      if (OOB(nxt) || cmd[nxt] != "0") continue;
      cmd[nxt].clear();
      cmd[nxt] = cmd[cur] + c;
      q.push(nxt);
    }
  }
  return ret;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int a, b;
    cin >> a >> b;
    cout << bfs(a, b) << '\n';
  }
}