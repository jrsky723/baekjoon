#include <bits/stdc++.h>
using namespace std;

int n;

struct Node {
  map<string, Node*> child;
  bool isEnd;
  Node() : isEnd(false) {}
  void insert(Node* root, vector<string>& v) {
    Node* cur = root;
    for (auto s : v) {
      if (cur->child[s] == NULL) cur->child[s] = new Node;
      cur = cur->child[s];
    }
    cur->isEnd = true;
  }

  void print(int idx) {
    if (child.empty()) return;
    for (auto nxt : child) {
      for (int i = 0; i < idx; i++) cout << ' ';
      cout << nxt.first << '\n';
      nxt.second->print(idx + 1);
    }
  }
};

vector<string> split(string& s) {
  vector<string> v;
  string temp;
  for (auto c : s) {
    if (c == '\\') {
      v.push_back(temp);
      temp = "";
    } else
      temp += c;
  }
  v.push_back(temp);
  return v;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  Node* root = new Node;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> s;
    vector<string> v = split(s);
    root->insert(root, v);
  }
  root->print(0);
}