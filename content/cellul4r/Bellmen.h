/**
 * Author: Theerada Siri
 * Description: find shortest path handle negative weight.
 * Time: O(V*E)
 */
// Edge List
struct Edge {
    int u, v, w;
};
vector<Edge> edges;
// bellman-ford:
vector<int> dist(n+1, INF);
dist[start] = 0;
int count = 0;
bool found_changes = false;
bool neg_cycle = false;
do {
    found_changes = false;
    for (auto edge : edges) {
        int u = edge.u, v = edge.v, w = edge.w;
        if (dist[u]+w < dist[v]) {
            dist[v] = dist[u]+w;
            found_change = true;
        }
    }
    ++count;
    if (count > n-1 && found_changes) {
        neg_cycle = true;
        break;
    }
} while (found_changes);
