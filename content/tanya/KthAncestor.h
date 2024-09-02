/**
 * Author: Suthana Kwaonueng
 * Description: find kth-ancestor of a tree-node
 * Time: O(\log N) 
 */
int kth_ancestor(int node,int k){
    if(depth[node] < k)return -1;
    for(int i = 0;i < LOG; ++i){
        if(k & (1<<i)){
            node = up[node][i];
        }
    }
    return node;
}
