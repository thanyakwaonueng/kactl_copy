/**
 * Author: Theerada Siri
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
// EQ is string s in range [i,L), and range [j,L)
p[0] = { 1, 1 }, p[1] = { dist(gen) | 1, dist(gen) };
for(int i = 1; i <= (ll)s.size(); i++) {
    p[i] = p[i - 1] * p[1];
    h[i] = h[i - 1] * p[1] + make_pair(s[i - 1], s[i - 1]);
}
