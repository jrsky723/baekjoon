#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  map<char, TrieNode *> child;
  bool isStop;

  TrieNode() : isStop(false) {}

  ~TrieNode() {
    for (auto nxt : child) delete nxt.second;
  }

  void insert(string &s) {
    auto cur = this;
    for (auto c : s) {
      if (cur->child[c] == NULL) {
        cur->child[c] = new TrieNode;
        if (!cur->isStop && cur->child.size() > 1) cur->isStop = true;
      }
      cur = cur->child[c];
    }
    cur->isStop = true;
  }

  int writeCnt(string &s) {
    int cnt = 0;
    auto cur = this;
    for (auto c : s) {
      if ((cur -> isStop)) cnt++;
       cur = cur->child[c];
    }
    return cnt;
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cout <<fixed; cout.precision(2);
  double n;
  while (cin >> n) {
    vector<string> v(n);
    TrieNode *root = new TrieNode;
    for (int i = 0; i < n; i++) {
      cin >> v[i];
      root->insert(v[i]);
    }
    double sum = 0;
    root->isStop = true;
    for (auto s : v) {
      sum += root->writeCnt(s);
    }
    cout << round((sum/n) * 100) / 100 <<'\n';
  }
}