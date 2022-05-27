#include <iostream>
using namespace std;

void hanoi(int n, int from, int aux, int to) {
  if (n == 1) {
    cout << from << ' ' << to << '\n';
    return;
  } else {
    hanoi(n - 1, from, to, aux);
    cout << from << ' ' << to << '\n';
    hanoi(n - 1, aux, from, to);
  }
}
int main() {
  int N;
  cin >> N;
  cout << (1 << N) - 1 << '\n';
  hanoi(N, 1, 2, 3);
}