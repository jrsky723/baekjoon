#include <bits/stdc++.h>
using namespace std;

bool state[4000005];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  fill(state + 2, state + n + 1, 1);
  for (int i = 2; i * i <= n; i++)
    for (int j = i * i; j <= n; j += i) state[j] = false;
  
  vector<int> prime;
  for (int i = 2; i <= n; i++) if(state[i]) prime.push_back(i);

  int en = 0;
  int cnt = 0;
  int tot = 0;
  if (!prime.empty()) tot = prime[0]; 
  for (int st = 0; st < prime.size(); st++) {
    while(en < prime.size() && tot < n) {
      en++;
      tot += prime[en];
    }
    if (tot == n) cnt++;
    tot -= prime[st];
  }
  cout << cnt;
}

//정답코드
// Authored by : heheHwang
// Co-authored by : -
// http://boj.kr/d1ba3e452d8842d7a9e56640231e25f5
// #include <bits/stdc++.h>
// using namespace std;

// const int MXN = 4000002;
// vector<bool> seive(MXN, true);
// vector<int> primes;
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
  
//   for(int i=2; i*i<MXN; i++){
//     if (!seive[i]) continue;
//     for (int j = i * i; j < MXN; j += i) 
//       seive[j] = false;
//   }
//   for (int i = 2; i < MXN; i++) if (seive[i]) primes.push_back(i);
//   primes.push_back(0);

//   int target, s = 0, e = 1, ans = 0, tmpSum = primes[0];
//   cin >> target;
//   while (1) {
//     if (tmpSum == target) ans++;
//     if (tmpSum <= target) tmpSum += primes[e++];
//     if (target < tmpSum) tmpSum -= primes[s++];
//     if (e == int(primes.size())) break;
//   }
//   cout << ans;
// }