#include <bits/stdc++.h>
using namespace std;
//정답에서는 STL List를 사용, 여기선 야매리스트를 구현
const int MX = 600005;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;

void traverse() {
    int cur = nxt[0];
    while (cur != -1) {
        cout << dat[cur];
        cur = nxt[cur];
    }
}

void insert(int addr, char c) {
    dat[unused] = c;
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr) {
    nxt[pre[addr]] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = pre[addr];
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    fill(pre, pre + MX, -1);
    fill(nxt, nxt + MX, -1);
    int n = 0;
    string str;
    cin >> str;
    int len = str.length();
    int cur = 0;
    for (char c : str) {
        insert(cur, c);
        cur = nxt[cur];
    }
    cin >> n;

    while (n--) {
        char cmd;
        cin >> cmd;
        switch (cmd) {
        case 'L': 
            if (pre[cur]!= -1) cur = pre[cur];
            break;
        case 'D': 
            if (nxt[cur] != -1) cur = nxt[cur];
            break;
        case 'B': 
            if (pre[cur] != -1) {
                erase(cur);
                cur = pre[cur];
            }
            break;
        case 'P': 
            char c;
            cin >> c;
            insert(cur, c);
            cur = nxt[cur];
            break;
        default:
            break;
        }
    }
    traverse();
}

//정답
// Authored by : BaaaaaaaaaaarkingDog
// Co-authored by : -
// http://boj.kr/84654f16875542e6a84d3da7e4cf0dac
// #include <bits/stdc++.h>
// using namespace std;

// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   string init;
//   cin >> init;
//   list<char> L;
//   for (auto c : init) L.push_back(c);
//   auto cursor = L.end();
//   int q;
//   cin >> q;
//   while (q--) {
//     char op;
//     cin >> op;
//     if (op == 'P') {
//       char add;
//       cin >> add;
//       L.insert(cursor, add);
//     }
//     else if (op == 'L') {
//       if (cursor != L.begin()) cursor--;
//     }
//     else if (op == 'D') {
//       if (cursor != L.end()) cursor++;
//     }
//     else { // 'B'
//       if (cursor != L.begin()) {
//         cursor--;
//         cursor = L.erase(cursor);
//       }
//     }
//   }
//   for (auto c : L) cout << c;
// }