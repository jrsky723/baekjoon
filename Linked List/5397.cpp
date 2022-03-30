#include <bits/stdc++.h>
using namespace std;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    
    cin>>n;

    while(n--){
        list<char> L = {};
        auto cursor = L.begin();
        string str;
        
        cin>>str;
        for(auto c : str){
            switch(c){
                case '<': if (cursor != L.begin()) cursor--;
                    break;
                case '>': if (cursor != L.end()) cursor++;
                    break;
                case '-': if (cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
                break;
                default : L.insert(cursor, c); 
                    break;  //switch case 실수 조심 할 것
            }
        }
        for (auto c : L) cout << c;
        cout<<'\n';
    }
}

//정답
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/49ff74ffdded4e0381138dabbaf8405b
// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n;

//   cin >> n;

//   for (int i = 0; i < n; i++) {
//     list<char> L = {};
//     string s;
//     auto p = L.begin();

//     cin >> s;
//     for (auto c : s) {
//       if (c == '<') {
//         if (p != L.begin()) p--;
//       }
//       else if (c == '>') {
//         if (p != L.end()) p++;
//       }
//       else if (c == '-') {
//         if (p != L.begin()) {
//           p--;
//           p = L.erase(p);
//         }
//       }
//       else
//         L.insert(p, c);      
//     }
//     for (auto c : L) cout << c;
//     cout << '\n';
//   }
// }