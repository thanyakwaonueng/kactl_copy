/**
 * Author: Theerada Siri
 * Description: mat[right node] is a left node or -1
 * edges from left to right
 * Time: O(abs(left)*M)
 */
bool dfs(ll u) {
	if (used[u]) return 0;
	used[u] = 1;
	for (ll v: edges[u])
	if (mat[v]==-1 || dfs(mat[v]))
		return mat[v] = u,1;
	return 0;
}
memset(mat, -1, sizeof mat);
for (ll u=0; u<n; ++u) {
  memset(used, 0, sizeof used);
	flow += dfs(u);
}
