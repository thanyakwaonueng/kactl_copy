/**
 * Author: Theerada Siri
 * Description: Centroid decomposition
 *
 * 
 * Time: O()
 */

vl tree[N];
ll sz[N], cPar[N], lvl[N]; //lvl is 1-indexed

ll getSize(ll i, ll p) {
    sz[i] = 1;
    for(ll j : tree[i])
        if(j - p && !lvl[j])
            sz[i] += getSize(j, i);
    return sz[i];
}

ll centroid(ll i, ll p, ll n) {
    for(ll j : tree[i])
        if(j - p && !lvl[j] && sz[j] > n / 2)
            return centroid(j, i, n);
    return i;
}

ll decomp(ll i, ll l) {
    ll cent = centroid(i, -1, getSize(i, -1));
    lvl[cent] = l;
    for(ll j : tree[cent]) if(!lvl[j])
        cPar[decomp(j, l + 1)] = cent;
    return cent;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    G(n)
    F(i, 0, n - 1) {
        G(u) G(v)
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    ll root = decomp(1, 1);
}
