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
const int  N = 1e6+7;
const int M = 1e9+7;
const ll oo = 3e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

long long GetRandom(long long l, long long r) {
    return uniform_int_distribution<long long> (l, r)(rng);
}

long long cal(int x, int i) {
    if (x < i) return 0;
    if (x % 2 == 1) return -(x - i + 1) + max(0, (x - 1)/2 - i + 1) + max(0, (x - 1) / 2 - i + 1);
    return - (x - i + 1) + max(0, x / 2 - i + 1) + max(0, x/2 - i);
}

void solve() {
    string t; cin >> t;
    int n = t.size();
    vector <char> s(n + 10);
    for (int i = 1; i <= n; i++) s[i] = t[i - 1];
    vector <int> l;
    int len = 1; 
    for (int i = 2; i <= n; i++) {
        if (s[i] != s[i - 1]) {
            l.push_back(len);
            len = 1;
        }
        else len++;
    }
    l.push_back(len);
    cout << n << ' ';
    long long sum = 0;
    sort (all(l));
    int j = 0;
    for (auto x: l) sum += x;
    for (int i = 2; i <= n; i++) {
        while (j < l.size()) {
            if (l[j] < i) {
                sum -= l[j];
                j++;
            }
            else break;
        }
        cout << sum - 1ll * (i - 1) * (l.size() - j) + cal(l.back(), i) << " ";
    }
    cout << '\n';
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
    while (t--) solve();


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
