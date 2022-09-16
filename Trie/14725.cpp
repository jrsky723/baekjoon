#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  map<string, TrieNode*> child;
  void insert(vector<string> v) {
    auto cur = this;
    for (auto s : v) {
      if (cur->child[s] == NULL) cur->child[s] = new TrieNode;
      cur = cur->child[s];
    }
  }
  void print(int idx) {
    for (auto nxt : child) {
      for (int i = 0; i < idx; i++) cout << "--";
      cout << nxt.first << '\n';
      nxt.second->print(idx + 1);
    }
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  TrieNode* root = new TrieNode;
  int n, k;
  cin >> n;

  while (n--) {
    cin >> k;
    vector<string> v(k);
    for (int i = 0; i < k; i++) cin >> v[i];
    root->insert(v);
  }
  root->print(0);
}