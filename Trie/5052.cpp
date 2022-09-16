#include <bits/stdc++.h>
using namespace std;

const int MX = 10000 * 10 + 5, ROOT = 1;
int n, tc, unused = 2;
int nxt[MX][10];
bool chk[MX];

void init() {
  for (int i = 0; i < MX; i++) fill(nxt[i], nxt[i] + 10, -1);
  fill(chk, chk + MX, 0);
  unused = 2;
}

int c2i(char c) { return c - '0'; }

void insert(string &s) {
  int cur = ROOT;
  for (auto c : s) {
    if (nxt[cur][c2i(c)] == -1) nxt[cur][c2i(c)] = unused++;
    cur = nxt[cur][c2i(c)];
  }
  chk[cur] = true;
}

bool consis(string &s) {
  int cur = ROOT;
  for (int i = 0; i < s.size(); i++) {
    if (chk[cur]) return false;
    cur = nxt[cur][c2i(s[i])];
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while (tc--) {
    init();
    vector<string> book;
    cin >> n;
    while (n--) {
      string s;
      cin >> s;
      book.push_back(s);
      insert(s);
    }
    bool ans = true;
    for (auto s : book)
      if (!consis(s)) ans = false;
    cout << (ans ? "YES" : "NO") <<'\n';
  }
}