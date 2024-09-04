/**
 * Author: Theerada Siri
 * Description: suffix tree, NN here is number of nodes, which is like 2n+10
 *to[] is edges, root is idx 1
 * lf[] and rt[] are edge info as half open interval into s
 */
map<char, ll> to[NN], lk[NN];
ll lf[NN], rt[NN], par[NN], path[NN];
#define att(a, b, c) to[par[a]=b][s[lf[a]=c]]=a;
void build(string &s) {
	ll n=s.size(), z=2;
	lf[1]--;
	for (ll i=n-1; i+1; i--) {
		ll v, V=n, o=z-1, k=0;
		for (v=o; !lk[v].count(s[i]) && v; v=par[v])
			V -= rt[path[k++]=v]-lf[v];
		ll w = lk[v][s[i]]+1;
		if (to[w].count(s[V])) {
			ll u = to[w][s[V]];
			for (rt[z]=lf[u]; s[rt[z]]==s[V]; rt[z]+=rt[v]-lf[v])
				v=path[--k], V+=rt[v]-lf[v];
			att(z, w, lf[u])
			att(u, z, rt[z])
			lk[v][s[i]] = (w = z++)-1;
		}
		lk[o][s[i]] = z-1;
		att(z, w, V)
		rt[z++] = n;
	}
}
