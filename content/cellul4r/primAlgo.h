/**
 * Author: Theerada Siri
 * Description: find minimum spanning tree with Prim Algorithm.
 * Time: O(\log(V)*E)
 */
using pii = pair<int, int>;
vector<int> dist(n+1, INF);
vector<bool> visited(n+1, false);
priority_queue<pii, vector<pii>, greater<pii>> Q;
dist[start] = 0;
Q.push({dist[start], start});
int sum = 0;
while (!Q.empty()) {
    int u = Q.top().second, d = Q.top().first;
    Q.pop();
    if (visited[u])
        continue;
    visited[u] = true;
    sum += dist[u];
    for (auto vw : G[u]) {
        int v = vw.first;
        int w = vw.second;
        if (!visited[v] && w < dist[v]) {
            dist[v] = w;
            Q.push({dist[v], v}) 
        }
    }
}
