#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
  map<char, TrieNode*> child;

  string insert(string& s) {
    string ret;
    char lastC = '0';
    auto cur = this;
    for (auto c : s) {
      if (cur->child[c] == NULL) {
        cur->child[c] = new TrieNode;
        if (lastC == '0') lastC = c;
      } else
        ret += c;
      cur = cur->child[c];
    }
    if (lastC != '0') ret += lastC;
    return ret;
  }
};

map<string, int> ids;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  TrieNode* root = new TrieNode;
  int n;
  cin >> n;
  while (n--) {
    string s;
    cin >> s;
    ids[s]++;
    cout << root->insert(s);
    if (ids[s] > 1) cout << ids[s];
    cout << '\n';
  }
}