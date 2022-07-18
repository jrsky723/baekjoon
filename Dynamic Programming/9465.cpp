#include <bits/stdc++.h>
using namespace std;

int s[2][100005];
int d[2][100005];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < 2; i++)
      for (int j = 1; j <= n; j++) cin >> s[i][j];
    d[0][1] = s[0][1], d[1][1] = s[1][1]; 
    for (int i = 2; i <= n; i++) {
      d[0][i] = max(max(d[0][i - 2], d[1][i - 2]) + s[0][i], d[1][i - 1] + s[0][i]);
      d[1][i] = max(max(d[0][i - 2], d[1][i - 2]) + s[1][i], d[0][i - 1] + s[1][i]);
    }
    cout << max({d[0][n], d[1][n], d[0][n - 1], d[1][n - 1]}) << '\n';
  }
}

//정답코드

// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/11776ce32bae48799ae66340d730cfd4
// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   int tc;
//   cin >> tc;
//   while (tc--) {
//     int N;
//     cin >> N;
//     vector<vector<int>> arr(N, vector<int>(2)), dp(N, vector<int>(2)); // N by 2 vector를 선언
//     for (int j = 0; j < 2; j++)
//       for (int i = 0; i < N; i++)
//         cin >> arr[i][j];
    
//     for (int i = 0; i < N; i++) {
//       for (int j = 0; j < 2; j++) {
//         int v = 0;
//         if (i > 1) v = max(dp[i - 2][0], dp[i - 2][1]);
//         if (i > 0) v = max(v, dp[i - 1][1 - j]);
//         dp[i][j] = v + arr[i][j];
//       }
//     }
//     cout << max(dp[N - 1][0], dp[N - 1][1]) << '\n';
//   }
// }