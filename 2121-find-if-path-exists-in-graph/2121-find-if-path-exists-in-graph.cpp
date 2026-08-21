class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(source);
        while(!q.empty()){
            int i = q.front();
            q.pop();
            visited[i] = true;
            for(int j : adj[i]){
                if(!visited[j]){
                    q.push(j);
                }
            }
        }
        return visited[destination];
    }
};