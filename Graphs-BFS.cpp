#include "bits/stdc++.h"

using namespace std;

const int N = 1e5+2;
bool visited[N];
vector<int> adj[N];



void bfs(int s){

    queue<int> q;

    q.push(s);

    visited[s] = true;
    
    while(!q.empty()){
        int d = q.front();
        
        q.pop();
        cout << d << endl;
     
        vector<int> :: iterator it;
        for(it = adj[s].begin(); it!=adj[s].end(); it++){
            if(!visited[*it]){
                visited[*it] = true;
                q.push(*it);
            }
        }
    }
}



int main()
{
    cout<<"Hello World"<<endl;
    for (int i = 0; i<N; i++ ){
        visited[i] = false;
    }
    //No of nodes and edges
    int v, e;
    cin >> v >> e;
    
    //X and Y are elements of edges
    int x, y ;
    for(int i =0; i < e; i++){
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    
    } 
    
    //starting node
    
    bfs(1);
    
    
    

    return 0;
}
