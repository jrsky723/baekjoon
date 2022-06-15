#include <bits/stdc++.h>
using namespace std;
int l, c;
char ch[16];
int mask[16];
bool isVowel(char c) {
  for (char x : "aeiou")
    if (c == x) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> l >> c;
  for (int i = 0; i < c; i++) cin >> ch[i];
  for (int i = l; i < c; i++) mask[i] = 1;
  sort(ch, ch + c);
  do {
    int vow = 0, cons = 0;
    for (int i = 0; i < c; i++) {
      if (mask[i]) continue;
      if (isVowel(ch[i]))
        vow++;
      else
        cons++;
    }
    if (vow < 1 || cons < 2) continue;
    for (int i = 0; i < c; i++)
      if (!mask[i]) cout << ch[i];
    cout << '\n';
  } while (next_permutation(mask, mask + c));
}
//정답코드
// #include <bits/stdc++.h>
// using namespace std;

// int l, c;
// char s[20];

// bool aeiou(char t){
//   return t == 'a' || t == 'e' || t == 'i' || t == 'o' || t == 'u';
// }

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   cin >> l >> c;
//   for(int i = 0; i < c; i++) cin >> s[i];
//   sort(s, s+c);
//   vector<int> brute(c);
//   for(int i = l; i < c; i++) brute[i] = 1;
//   do{
//     string ans;
//     int cnt1 = 0; // 모음의 수
//     for(int i = 0; i < c; i++){
//       if(brute[i] == 0){
//         ans += s[i];
//         if(aeiou(s[i])) cnt1++;
//       }      
//     }
//     if(cnt1 < 1 || l - cnt1 < 2) continue;
//     cout << ans << '\n';
//   }while(next_permutation(brute.begin(), brute.end()));
// }