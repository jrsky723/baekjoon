#include <bits/stdc++.h>
using namespace std;

const int MAX = 100000;
int n;
int inOrder[MAX + 1], postOrder[MAX + 1], idx[MAX + 1];
void preOrder(int inSt, int inEn, int poSt, int poEn) {
  if (inSt > inEn || poSt > poEn) return;
  int root = postOrder[poEn];
  cout << root << ' ';
  preOrder(inSt, idx[root] - 1, poSt, poSt + idx[root] - inSt - 1);
  preOrder(idx[root] + 1, inEn, poSt + idx[root] - inSt, poEn - 1);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) cin >> inOrder[i];
  for (int i = 0; i < n; i++) cin >> postOrder[i];
  for (int i = 0; i < n; i++) idx[inOrder[i]] = i;
  preOrder(0, n - 1, 0, n - 1);
}