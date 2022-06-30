#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int a_size, b_size, cnt = 0;
    cin >> a_size >> b_size;
    vector<int> A(a_size),B(b_size);
    for (int i = 0; i < a_size; i++) cin >> A[i];
    for (int i = 0; i < b_size; i++) cin >> B[i];
    sort(A.begin(), A.end(), greater<>());
    sort(B.begin(), B.end(), greater<>());  //n^2 풀이 : upper_bound 이용할 것
    for (int i = 0; i < a_size; i++) {
      if (A[i] <= B.back()) break;
      for (int j = 0; j < b_size; j++) {
        if (A[i] > B[j]) {
          cnt += b_size - j;
          break;
        }
      }
    }
    cout << cnt <<'\n';
  }
}
//정답코드
//(n+m)log(n+m) 풀이
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c8698bc57ac343dea8f836660aecc0b4
// #include <bits/stdc++.h>
// using namespace std;

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int t;
//   cin >> t;
//   while(t--){
//     int n, m;
//     cin >> n >> m;
//     vector<pair<int,int>> v(n+m);
//     for(int i = 0; i < n; i++){
//       int a;
//       cin >> a;
//       v[i] = {a, 0};
//     }
//     for(int i = n; i < n+m; i++){
//       int b;
//       cin >> b;
//       v[i] = {b, 1};
//     }
//     sort(v.begin(), v.end()); 
//     int cnt = 0; // 현재까지 나온 b의 개수
//     int ans = 0;
//     for(int i = 0; i < n+m; i++){
//       if(v[i].second == 0) // 현재 보는 수가 A에 속한 수
//         ans += cnt;
//       else // 현재 보는 수가 B에 속한 수
//         cnt++;
//     }
//     cout << ans << '\n';
//   }
// }

//(n + m)logn 풀이
// Authored by : tongnamuu
// Co-authored by : -
// http://boj.kr/c1c7cd2d6487442f83a3fc8f1267c058

// #include <bits/stdc++.h>
// using namespace std;
// int a[20001];
// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int T;cin>>T;
//   while(T--){
//     int n,m;cin>>n>>m;
//     for(int i=0;i<n;++i) cin>>a[i];
//     sort(a, a+n);
//     int ans = 0;
//     for(int i=0;i<m;++i){
//       int num;cin>>num;
//       int index = upper_bound(a, a+n, num) - a;
//       ans += n - index;
//     }
//     cout<<ans<<'\n';
//   }
// }
/*
이분탐색을 이용한 풀이
*/