#include <iostream>

using namespace std;
int a[1005];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int value = n;
  for (int i = 0; i < n; i++) {
    if (a[i] == 1) value--;
    for (int j = 2; j < a[i]; j++)
      if (a[i] % j == 0) {
        value--;
        break;
      }
  }
  cout << value;
}