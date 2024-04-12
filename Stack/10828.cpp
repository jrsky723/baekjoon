#include <bits/stdc++.h>

using namespace std;

const int MAX = 10000;

int arr[MAX + 5];
int arr_size = 0;
bool is_arr_empty = true;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  while (n--) {
    string s;
    cin >> s;
    if (s == "push") {
      if (is_arr_empty) is_arr_empty = false;
      int x;
      cin >> x;
      arr[arr_size++] = x;
    } else if (s == "pop") {
      if (arr_size == 0) {
        cout << -1 << '\n';
      } else {
        cout << arr[arr_size - 1] << '\n';
        arr[arr_size-- - 1] = 0;
        if (arr_size == 0) is_arr_empty = true;
      }
    } else if (s == "size") {
      cout << arr_size << '\n';

    } else if (s == "empty") {
      cout << is_arr_empty << '\n';

    } else {
      if (arr_size == 0) {
        cout << -1 << '\n';
      } else {
        cout << arr[arr_size - 1] << '\n';
      }
    }
  }
}

// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c792146f735b42559e8cb3bf21e61fa9
// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n;
//   cin >> n;
//   stack<int> S;
//   while(n--){ // n번 반복
//     string c;
//     cin >> c;
//     if(c=="push"){
//       int t;
//       cin >> t;
//       S.push(t);
//     }
//     else if(c=="pop"){
//       if(S.empty()) cout << -1 << '\n';
//       else{
//         cout << S.top() << '\n';
//         S.pop();
//       }
//     }
//     else if(c=="size")
//       cout << S.size() << '\n';
//     else if(c=="empty")
//       cout << (int)S.empty() << '\n';
//     else{ // top
//       if(S.empty()) cout << -1 << '\n';
//       else cout << S.top() << '\n';
//     }
//   }
// }