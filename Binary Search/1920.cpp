#include <bits/stdc++.h>
using namespace std;
const int MAX = 100'000;
int arr[MAX + 5];

bool search(int m, int start, int end) {
    if (start > end) return false;
    else {
        int mid = (start + end) / 2;
        if (arr[mid] < m) return search(m, mid + 1, end);
        else if (arr[mid] > m) return search(m, start, mid - 1);
        else return true;
    }
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr + 1, arr + 1 + n);
    int t;
    cin >> t;
    while (t--) {
        int m;
        cin >> m;
        cout << search(m, 1, n) << '\n';
    }
}