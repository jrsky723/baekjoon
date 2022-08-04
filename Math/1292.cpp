#include <bits/stdc++.h>
using namespace std;

int arr[2000];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int num = 1, cur = 1;
  while (cur <= 1000) {
    int cnt = 0;
    while (cnt < num) {
      arr[cur++] = num;
      cnt++;
    }
    num++;
  }
  int a, b;
  cin >> a >> b;
  int sum = 0;
  for (int i = a; i <= b; i++) sum += arr[i];
  cout << sum;
}