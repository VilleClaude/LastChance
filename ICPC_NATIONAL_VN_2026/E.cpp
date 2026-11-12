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

int check(int x, int y, int k) {
    map <int, int> ma;
    int temp = x;
    while (temp > 0) {
        ma[temp%10]++;
        temp /= 10;
    }
    temp = y;
    int last = 0;
    while (temp > 0) {
        ma[temp%10]++;
        last = temp % 10;
        temp /= 10;
    }
    if (ma.size() != 6) return M;
    if (k * (x % 10) == last) return x + y;
    return M;
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
    
    int ans = N;
    
    int k; cin >> k;
    for (int x = 100; x <= 999; x++) {
        for (int y = 100; y <= 999; y++) {
            int temp = check(x, y, k);
            ans = min(ans, temp);
        }
    }
    
    cout << ans << '\n';


    cerr << "Time elapsed: " << TIME << " s.\n";
    return 0;
}
