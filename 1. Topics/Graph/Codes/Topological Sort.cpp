//lightoj 1034 problem shows how you can use topsort to visit all node using minimum number of nodes
//topsort arranges the nodes in such a way that each nodes precedes all the nodes it points to. 
//but this problem did not specify that the graph is acyclic
//but nontheless the stack will give the nodes from where we can reach all nodes using minimum nodes


stack <int> stk;
void topsort(int v) {
    visited[v] = true;

    for (auto u : graph[v])
        if (!visited[u])
            topsort(u);
    stk.push(v);
}
