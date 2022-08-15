#include <bits/stdc++.h>
using namespace std;

int main (){ 
  ios::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--){
    int k;
    cin >> k;
    multiset<int> Q;
    while (k--) {
	    char IoD;
	    int n;
	    cin >> IoD >> n;
	    if (IoD == 'I')Q.insert(n);
	    else if (IoD == 'D'){
	      if (Q.empty ()) continue;
	      if (n == 1) Q.erase(prev(Q.end()));
	      else if (n == -1) Q.erase(Q.begin());
	    }
	  }
  if (Q.empty ()) cout << "EMPTY\n";
	else cout << *prev(Q.end()) << ' ' << *Q.begin()<<'\n';
  }
}
//정답코드
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/c34ee5c887ee4ab1b913692c92ab56cc
// #include <bits/stdc++.h>
// using namespace std;

// int main(void){
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int t;
//   cin >> t;
//   while(t--){
//     int k;
//     cin >> k;
//     multiset<int> ms;
//     while(k--){
//       char com;
//       cin >> com;
//       if(com == 'D'){
//         int q;
//         cin >> q;
//         if(ms.empty()) continue;
//         if(q == 1) ms.erase(prev(ms.end()));
//         else ms.erase(ms.begin());
//       }
//       else{
//         int q;
//         cin >> q;
//         ms.insert(q);
//       }
//     }
//     if(ms.empty()) cout << "EMPTY\n";
//     else{
//       cout << *prev(ms.end()) << ' ' << *ms.begin() << '\n';
//     }
//   }
// }