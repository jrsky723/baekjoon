#include <bits/stdc++.h>
using namespace std;

int probLevel[100005];
int probAlgo[100005];
set<int> probByLevel[102];
set<int> probByAlgoLevel[102][102];

void add() {
  int num, lev, algo;
  cin >> num >> lev >> algo;
  probLevel[num] = lev;
  probAlgo[num] = algo;
  probByLevel[lev].insert(num);
  probByAlgoLevel[algo][lev].insert(num);
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n, m;
  cin >> n;
  for (int i = 0; i < n; i++) add();
  cin >> m;
  while (m--) {
    string s;
    cin >> s;
    if (s == "add")
      add();
    else if (s == "recommend") {
      int g, x;
      cin >> g >> x;
      if (x == 1) {
        for (int i = 100; i >= 1; i--) {
          if (!probByAlgoLevel[g][i].empty()) {
            cout << *prev(probByAlgoLevel[g][i].end()) << '\n';
            break;
          }
        }
      } else {
        for (int i = 1; i <= 100; i++) {
          if (!probByAlgoLevel[g][i].empty()) {
            cout << *probByAlgoLevel[g][i].begin() << '\n';
            break;
          }
        }
      }
    } else if (s == "recommend2") {
      int x;
      cin >> x;
      if (x == 1) {
        for (int i = 100; i >= 1; i--) {
          if (!probByLevel[i].empty()) {
            cout << *prev(probByLevel[i].end()) << '\n';
            break;
          }
        }
      } else {
        for (int i = 1; i <= 100; i++) {
          if (!probByLevel[i].empty()) {
            cout << *probByLevel[i].begin() << '\n';
            break;
          }
        }
      }
    } else if (s == "recommend3") {
      int x, l;
      cin >> x >> l;
      if (x == 1) {
        for (; l <= 100; l++) {
          if (!probByLevel[l].empty()) {
            cout << *probByLevel[l].begin() << '\n';
            break;
          }
        }
        if (l > 100) cout << -1 << '\n';
      } else {
        l--;
        for (; l >= 1; l--) {
          if (!probByLevel[l].empty()) {
            cout << *prev(probByLevel[l].end()) << '\n';
            break;
          }
        }
        if (l < 1) cout << -1 << '\n';
      }
    } else {
      int num;
      cin >> num;
      probByLevel[probLevel[num]].erase(num);
      probByAlgoLevel[probAlgo[num]][probLevel[num]].erase(num);
    }
  }
}

//정답코드
// Authored by : heheHwang
// Co-authored by : BaaaaaaaaaaarkingDog
// http://boj.kr/c26933e668ff4856874db1108942533c
// #include <bits/stdc++.h>
// using namespace std;

// string op;
// int N, L, P, G, x;
// pair<int, int> probLevel[100'002]; // 문제의 (난이도, 분류) 저장
// set<int> probByL[102];  // 난이도별로 문제 저장
// set<int> probByGL[102][102];  // (분류, 난이도) 별로 문제 저장

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> N;
//   while (N--) {
//     cin >> P >> L >> G;
//     probLevel[P] = {L, G};
//     probByL[L].insert(P);
//     probByGL[G][L].insert(P);
//   }
//   cin >> N;
//   while (N--) {
//     cin >> op;
//     if (op == "recommend") {
//       cin >> G >> x;
//       if (x == 1) {
//         for (int i = 100; i >= 0; i--) {
//           if (probByGL[G][i].empty()) continue;
//           cout << *(prev(probByGL[G][i].end())) << '\n';
//           break;
//         }
//       } else {
//         for (int i = 0; i < 101; i++) {
//           if (probByGL[G][i].empty()) continue;
//           cout << *probByGL[G][i].begin() << '\n';
//           break;
//         }
//       }
//     }
    
//     else if(op == "recommend2"){
//       cin >> x;
//         if (x == 1) {
//         for (int i = 100; i >= 0; i--) {
//           if (probByL[i].empty()) continue;
//           cout << *(prev(probByL[i].end())) << '\n';
//           break;
//         }
//       } else {
//         for (int i = 0; i < 101; i++) {
//           if (probByL[i].empty()) continue;
//           cout << *probByL[i].begin() << '\n';
//           break;
//         }
//       }
//     }

//     else if(op == "recommend3"){
//       cin >> x >> L;
//       int ans = -1;
//       if(x == 1){
//         for(int i = L; i < 101; i++){
//           if(probByL[i].empty()) continue;
//           ans = *probByL[i].begin();
//           break;
//         }
//       }
//       else{
//         for(int i = L-1; i >= 0; i--){
//           if(probByL[i].empty()) continue;
//           ans = *(prev(probByL[i].end()));
//           break;
//         }
//       }
//       cout << ans << '\n';
//     }
    
//     else if (op == "add") {
//       cin >> P >> L >> G;
//       probLevel[P] = {L, G};
//       probByL[L].insert(P);
//       probByGL[G][L].insert(P);
//     }
    
//     else if (op == "solved") {
//       cin >> P;
//       tie(L, G) = probLevel[P];
//       probByL[L].erase(P);
//       probByGL[G][L].erase(P);
//     }
//   }
// }