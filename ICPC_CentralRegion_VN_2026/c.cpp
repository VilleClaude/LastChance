#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    long long ans = 0;
    int cnt=  0;
    for (int i = 1; i <= n; i++) {
        long long x; cin >> x;
        if (x >= m) {
            ans += x;
            cnt += 1;
        }
    }
    
    cout << cnt << " " << ans << '\n';
    return 0;
}
