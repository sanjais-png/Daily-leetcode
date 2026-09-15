class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        
        vector<vector<int>>dir = {{1,0} , {0,1} , {-1,0} , {0,-1}};
        vector<vector<bool>>visited(grid.size() , vector<bool>(grid[0].size(),false));
        int ans = 0;
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0; j < grid[0].size() ; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    queue<vector<int>>q;
                    q.push({i,j});
                    visited[i][j] = true;
                    while(!q.empty()){
                        vector<int>v = q.front();
                        q.pop();
                        for(int x = 0 ; x < 4 ; x++){
                            int rr = v[0] + dir[x][0];
                            int rc = v[1] + dir[x][1];
                            if(rr < 0 || rc < 0 || rr >= grid.size() || rc >= grid[0].size()){
                                ans++;
                            }else if(grid[rr][rc] == 0){
                                ans++;
                            }
                            else if(!visited[rr][rc] && grid[rr][rc] == 1){
                                q.push({rr,rc});
                                visited[rr][rc] = true;
                            }
                            
                        }
                    }
                }
            }
        }
        return ans;
    }
};