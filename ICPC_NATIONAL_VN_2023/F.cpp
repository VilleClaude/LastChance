#include <bits/stdc++.h>
#define TIME  (1.0 * clock() / CLOCKS_PER_SEC)
#define For(i,a,b) for(int i = a; i <= b; i++)
#define Ford(i,a,b) for(int i = a; i >= b; i--)
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define all(v) v.begin(),v.end()
#define RRH(v) v.resize(unique(all(v)) - v.begin())

using namespace std;
const int  N = 2e5+7;
const int M = 1e9+7;
const ll oo = 3e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long GetRandom(long long l, long long r) {
    return uniform_int_distribution<long long> (l, r)(rng);
}

int pre[N][4];

void solve() {
    string s; cin >> s;
    int n = s.size();
    pre[0][3] = pre[0][1] = pre[0][2] = 0;
    For (i, 1, n) {
        For (j, 1, 3) {
            pre[i][j] = pre[i - 1][j];
        }
        if (s[i - 1] == 'R') pre[i][1] += 1;
        if (s[i - 1] == 'P') pre[i][2] += 1;
        if (s[i - 1] == 'S') pre[i][3] += 1;
    }

    int max_win = 0, ans = 0;

    for (int k = 2; k <= n; k++) {
        int sum = 0;
        for (int i = 1; i <= n; i += k) {
            sum += max({pre[min(n, i + k - 1)][1] - pre[i - 1][1], pre[min(n,i + k - 1)][2] - pre[i - 1][2], pre[min(n,i + k - 1)][3] - pre[i - 1][3]});
        }
        if (sum >= max_win) {
            ans = k;
            max_win = sum;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);

    #define TASK ""
    if (fopen (".inp", "r")) {
        freopen (".inp", "r", stdin);
        freopen (".out", "w", stdout);
    }
    if(fopen(TASK".inp", "r")) {
        freopen(TASK".inp", "r", stdin);
        freopen(TASK".out", "w", stdout);
    }

    int t; cin >> t;
    while (t--) {
        solve();
    }


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
