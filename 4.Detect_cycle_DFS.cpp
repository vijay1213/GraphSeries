#include<bits/stdc++.h>
using namespace std;

bool checkCycleDFS(int node, int par, vector<int> &vis, vector<int> adj[]){
    vis[node] = 1;
    for(auto it : adj[node]){
        if(!vis[it]){
            if(checkCycleDFS(it, node, vis, adj)) return true;
        }
        else if(it != par) return true;
    }
    return false;
}

bool isCycle(int v, vector<int> adj[]){
    vector<int> vis(v, 0);
    
    
    for(int i=0; i<v; i++){
        if(!vis[i]){
            if(checkCycleDFS(i, -1, vis, adj)) return true;
        }
    }
    return false;
}

int main(){
    int n, m;
    cin>>n>>m;
    
    vector<int> adj[n];
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    if(isCycle(n, adj)) cout<<"Yes";
    else cout<<"No";
    return 0;
}
