#include <bits/stdc++.h>
using namespace std;
const int MAX = 10000000;
bool isPrime[MAX + 5];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  fill(isPrime, isPrime + MAX, 1);
  isPrime[0] = isPrime[1] = 0;
  for (int i = 2; i * i < MAX; i++) {
    if(!isPrime[i]) continue;
    for (int j = i * i; j < MAX; j += i) isPrime[j] = false;
  }
  int n;
  cin >> n;
  int temp = n;
  while (1) {
    string revS = to_string(temp);
    reverse(revS.begin(), revS.end());
    int rev = stoi(revS);
    if(temp == rev && n <= rev && isPrime[rev]) {
      cout << rev;
      break;
    }
    temp++;
  }
  return 0;
}