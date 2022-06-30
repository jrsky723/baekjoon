#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  string str;
  cin >> str;
  vector<string> vec;
  for (int i = 0; i < str.size(); i++) {
    string temp(str, i, str.size()); //substr(i) 사용해보기
    vec.push_back(temp);
  }
  sort(vec.begin(), vec.end());
  for (auto s : vec) cout << s << '\n';
}

//정답코드
// Authored by : std-freejia
// Co-authored by : -
//http://boj.kr/21378a10916b42d19dce4bc7c841a73c
// #include <bits/stdc++.h>
// using namespace std;

// string st;
// vector<string> v;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);

//   cin >> st;
//   int stringlen = st.length();
//   for(int i = 0; i < stringlen; i++) {
//     string temp = st.substr(i);
//     v.push_back(temp);
//   }
//   sort(v.begin(), v.end());
//   for(auto i : v) cout << i << '\n';
//   return 0;
// }