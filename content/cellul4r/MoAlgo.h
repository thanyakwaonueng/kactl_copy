/**
 * Author: Theerada Siri
 * Description: q is query idx's [l,r] closed
 * sort the query first and for each current we update
 * the value and find the total for each query.
 * Time: O(q*S+n*n/S)
 */
map<ll,ll> cnt;
set<pair<ll,ll>> best;
ll tot;
void update(ll i, ll d) {
  ll a = x[i];
  best.erase({cnt[a],a});
  cnt[a] += d;
  best.insert({cnt[a],a});
  tot = best.rbegin()->second;
}
ll S = sqrtl(n);
sort(q.begin(), q.end(), [&](ll a, ll b) {
	if (l[a]/S != l[b]/S) return l[a]/S < l[b]/S;
	return l[a]/S%2 ? r[a]>r[b] : r[a]<r[b];
});
ll curl=0, curr=-1;
for (auto i:q) {
	while(curr<r[i]) update(++curr, 1);
	while(curr>r[i]) update(curr--, -1);
	while(curl<l[i]) update(curl++, -1);
	while(curl>l[i]) update(--curl, 1);

	ans[i] = tot;
}

