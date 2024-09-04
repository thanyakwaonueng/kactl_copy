/**
 * Author: Theerada Siri
 * Description: find suffix array with string hashing.
 */
typedef long long int ll;
typedef pair<ll, ll> pl;
#define M 1000000321
#define OP(x, y) pl operator x (pl a, pl b) { return { a.first x b.first, (a.second y b.second) % M }; }
OP(+, +) OP(*, *) OP(-, + M -)
mt19937 gen(chrono::steady_clock::now().time_since_epoch().count());
uniform_int_distribution<ll> dist(256, M - 1);
#define H(i, l) (h[(i) + (l)] - h[i] * p[l])
#define EQ(i, j, l) (H(i, l) == H(j, l))
#define N 100010
string s;
pl p[N], h[N];
ll n, suff[N];
 ll lcp(ll i, ll j, ll l, ll r) { //can use any binary search function here
    if(l == r) return l;
    ll m = (l + r + 1) / 2;
    return EQ(i, j, m) ? lcp(i, j, m, r) : lcp(i, j, l, m - 1);
}
bool lexLess(ll i, ll lI, ll j, ll lJ) {
    if(EQ(i, j, min(lI, lJ))) return lI < lJ;
    ll m = lcp(i, j, 0, min(lI, lJ) - 1);
    return s[i + m] < s[j + m];
}
p[0] = { 1, 1 }, p[1] = { dist(gen) | 1, dist(gen) };
for(int i = 1; i <= (ll)s.size(); i++) {
    p[i] = p[i - 1] * p[1];
    h[i] = h[i - 1] * p[1] + make_pair(s[i - 1], s[i - 1]);
}
iota(suff, suff + n, 0); //sets suff[i] = i for all i
sort(suff, suff + n, [](ll i, ll j) { return lexLess(i, n - i, j, n - j); });
for(int i = 0; i < n; i++) cout << suff[i] << ' ';
    cout << '\n';
}
