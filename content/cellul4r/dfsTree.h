/**
 * Author: Theerada Siri
 * Description: 
 *
 * 
 * Time: O()
 */

vl graph[N], backIn[N], backOut[N], tree[N];
ll dep[N], par[N];

void dfs(ll i, ll p) {
    par[i] = p;
    dep[i] = dep[p] + 1;
    for(ll j : graph[i]) if(!dep[j]) {
        tree[i].push_back(j);
        dfs(j, i);
    } else if(dep[j] < dep[i] - 1) {
        backIn[j].push_back(i);
        backOut[i].push_back(j);
    }
}
