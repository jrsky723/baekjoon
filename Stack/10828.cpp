#include<bits/stdc++.h>
using namespace std;
int stc[MX];
int pos = 0;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin>>N;
    while(N--){
        string s;
        cin>>s;
        if(s == "push"){
            int i;
            cin>>i;
            stc[pos++] = i;
        }
        else if(s == "pop"){
            if(pos) {
                cout<<stc[--pos]<<'\n';
                stc[pos] = 0;
            }
            else cout<<-1<<'\n';
        }
        else if(s == "size"){
            cout<<pos<<'\n';
        }
        else if(s == "empty"){
            if(pos) cout<<0<<'\n';
            else cout<<1<<'\n';
        }
        else{
            if(pos) cout<<stc[pos-1]<<'\n';
            else cout<<-1<<'\n';
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