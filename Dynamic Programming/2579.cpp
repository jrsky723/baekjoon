#include <bits/stdc++.h>
using namespace std;

int S[302];
int D[302][3];
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, score = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> S[i];
  if (n == 1) {
    cout << S[1];
    return 0;
  }
  D[1][1] = S[1];
  D[1][2] = 0;
  D[2][1] = S[2];
  D[2][2] = S[1] + S[2];
  for (int i = 3; i <= n; i++) {
    D[i][1] = max(D[i - 2][1], D[i - 2][2]) + S[i];
    D[i][2] = D[i - 1][1] + S[i];
  }
  cout << max(D[n][1], D[n][2]);
}

//별해 코드
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/e93e56bb850a46378cf8f53486233cdc
// #include <bits/stdc++.h>
// using namespace std;

// int s[305];
// int n;
// int d[305];

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> n;
//   int tot = 0;
//   for(int i = 1; i <= n; i++){
//     cin >> s[i];
//     tot += s[i];
//   }
//   if(n <= 2){
//     cout << tot;
//     return 0;
//   }
//   d[1] = s[1];
//   d[2] = s[2];
//   d[3] = s[3];
//   for(int i = 4; i <= n-1; i++) d[i] = min(d[i-2],d[i-3])+s[i];
//   cout << tot - min(d[n-1],d[n-2]);
// }