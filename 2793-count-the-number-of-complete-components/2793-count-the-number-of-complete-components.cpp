class Solution {
public:

    int findComponents(vector<vector<int>>& adj , int n){
        queue<int>q;
        vector<bool>visited(n);
        int count = 0;
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                visited[i] = true;
                q.push(i);
            int v = 0 , edges = 0;
            while(!q.empty()){
                int cur = q.front();
                q.pop();
                v++;
                for(int i = 0 ; i < adj[cur].size() ;i++){
                    edges++;
                    if(!visited[adj[cur][i]]){
                        visited[adj[cur][i]] = true;
                        q.push(adj[cur][i]);
                    }
                }

            }
            int val = (v*(v-1));
            if(val == edges){count++;}
            }
        }
        return count;
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(int i = 0 ; i < edges.size() ; i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        int count = findComponents(adj , n);
        return count;
    }
};