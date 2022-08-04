#include <bits/stdc++.h>
using namespace std;

int n, layer;
int main(void) {
  cin >> n;
  n--;
  while (0 < (n -= 6*layer)) layer += 1;
  cout << ++layer;
}