/**
 * Author: Theerada Siri
 * Description: to find order on DAG.
 * Time: O(V+E)
 */
int indeg[N];
// edge(u,v) ++indeg[v]
queue<int> Q;
for (int u = 1; u <= n; ++u) {
    if (indeg[u] == 0)
        Q.push(u);
}
vector<int> seq; // sequence
while (!Q.empty()) {
    int u = Q.front();
    Q.pop();
    seq.push_back(u);
    for (auto v : G[u]) {
        --indeg[v];
        if (indeg[v] == 0)
            Q.push(v);
    }
}
