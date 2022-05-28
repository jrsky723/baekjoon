#include <bits/stdc++.h>
using namespace std;
const int MAX = 15;
int n;
int cnt = 0;
bool isused1[MAX];          // y
bool isused2[2 * MAX - 1];  // x+y
bool isused3[2 * MAX - 1];  // x-y+n-1

void func(int cur) {
  if (cur == n) {
    cnt++;
    return;
  }
  for (int j = 0; j < n; j++) {
    if (!isused1[j] && !isused2[cur + j] && !isused3[cur - j + n - 1]) {
      isused1[j] = isused2[cur + j] = isused3[cur - j + n - 1] = 1;
      func(cur + 1);
      isused1[j] = isused2[cur + j] = isused3[cur - j + n - 1] = 0;
    }
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  clock_t start,end;
  double result;
  start = clock();

  cin >> n;
  func(0);
  cout << cnt;

  end = clock(); 
  result = (double)(end - start);
  cout<<'\n'<<result; 
}