class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<vector<int>>q;
        for(int i = 0 ; i < m ; i++){
            for(int  j = 0 ; j < n ; j++){
                if(grid[i][j] == 1 && (i == 0 || j == 0 || i == m-1 || j == n-1) ){
                    q.push({i,j});
                }
            }
        }
        vector<vector<int>>dir = {{1,0},{0,1},{-1,0},{0,-1}};
        while(!q.empty()){
            vector<int>v = q.front();
            grid[v[0]][v[1]] = 0;
            q.pop();
            for(int i = 0 ; i < 4 ; i++){
                int rr = v[0] + dir[i][0];
                int rc = v[1] + dir[i][1];
                if(rr >= 0 && rc >= 0 && rr < m && rc < n && grid[rr][rc] == 1){
                    grid[rr][rc] = 0;
                    q.push({rr,rc});
                }
            }
        }
        int count = 0;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(grid[i][j] == 1){
                    count++;
                }
            }
        }
        return count;
    }
};