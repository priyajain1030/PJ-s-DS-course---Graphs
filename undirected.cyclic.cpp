
#include <bits/stdc++.h>
using namespace std;

int N;
 

bool cyclicbfs(vector<int> adj[], int s,
                        int V, vector<bool>& visited)
{

    vector<int> parent(V, -1);
 
    queue<int> q;
 
    
    visited[s] = true;
    q.push(s);
 
    while (!q.empty()) {
 
        
        int u = q.front();
        q.pop();
 
        
        for (auto v : adj[u]) {
            if (!visited[v]) {
                visited[v] = true;
                q.push(v);
                parent[v] = u;
            }
            else if (parent[u] != v)
                return true;
        }
    }
    return false;
}
 
bool isCyclicconnected(vector<int> adj[], int V)
{
    // Mark all the vertices as not visited
    vector<bool> visited(V, false);
 
    for (int i = 0; i < V; i++)
        if (!visited[i] && cyclicbfs(adj, i,
                                         V, visited))
            return true;
    return false;
}
 
// Driver program to test methods of graph class
int main()
{
    
    int v, e;
    vector<int> adj[v];
    cin >> v >> e;
    
    //X and Y are elements of edges
    int x, y ;
    for(int i =0; i < e; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    
 
    if (isCyclicconnected(adj, v))
        cout << "Cyclic";
    else
        cout << "Not Cyclic";
 
    return 0;
}