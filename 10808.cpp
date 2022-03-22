#include<bits/stdc++.h>
using namespace std;
int arr[26]; //전역에만 초기화할때 0으로 된다는걸 기억하자.
int main(){
    string s;
    cin>>s;
    
    for(auto i : s)
        for(int j = 0; j != 26; j++)
        if(i-'a'== j)              //그냥 i - 'a' 칸을 올려도 됌, 쓸데없는 for문을 만들었음.
        arr[j]++;                   

    for(int i = 0; i != 26; i++)
    cout<<arr[i]<<" ";

}

//정답 코드
// #include <bits/stdc++.h>
// using namespace std;

// int freq[26];
// int main(void) {
//   ios::sync_with_stdio(0);
//   cin.tie(0);            위 두개를 입력할 것, 속도 향상
//   string s;
//   cin >> s;
//   for(auto c : s)
//     freq[c-'a']++;
//   for(int i = 0; i < 26; i++)
//     cout << freq[i] << ' ';
// }