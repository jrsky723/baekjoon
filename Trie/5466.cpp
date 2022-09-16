#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
struct TrieNode {
  map<char, TrieNode *> child;
  bool isSave, isEnd;
  TrieNode() : isSave(false), isEnd(false) {}
  ~TrieNode() {
    for (auto nxt : child) delete nxt.second;
  }
  void insert(string &s) {
    auto cur = this;
    for (auto c : s) {
      if (cur->child[c] == NULL) cur->child[c] = new TrieNode;
      cur = cur->child[c];
    }
    cur->isEnd = true;
  }
  void save(string &s) {
    auto cur = this;
    cur->isSave = true;
    for (auto c : s) {
      if (cur->child[c] == NULL) {
        cur->child.erase(c);
        break;
      }
      cur = cur->child[c];
      if (!(cur->isSave)) cur->isSave = true;
    }
  }
  void dfs() {
    auto cur = this;
    if (!(cur->isSave)) {
      cnt++;
      return;
    }
    if (cur->isEnd) cnt++;
    for (auto nxt : child) nxt.second->dfs();
  }
};
int tc, n1, n2;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> tc;
  while (tc--) {
    TrieNode *root = new TrieNode;
    cnt = 0;
    string s;
    cin >> n1;
    while (n1--) {
      cin >> s;
      root->insert(s);
    }
    cin >> n2;
    while (n2--) {
      cin >> s;
      root->save(s);
    }
    root->dfs();
    cout << cnt << '\n';
    delete root;
  }
}