class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rows = grid.size() , col = grid[0].size();
        vector<vector<int>>dir = {{0,1},{1,0},{-1,0},{0,-1}};
        queue<vector<int>>q;

        int count = 0;
        for(int i = 0 ; i < rows ; i++){
            for(int j = 0 ; j < col ; j++){
                if(grid[i][j] == '1'){
                    count++;
                    grid[i][j] = '0';
                    q.push({i,j});
                    while(!q.empty()){
                        vector<int>v = q.front();
                        q.pop();
                        for(int x = 0 ; x < 4 ; x++){
                            int rc = v[0] + dir[x][0];
                            int rr = v[1] + dir[x][1];
                            if(rc >= 0 && rr >= 0 && rc<rows && rr<col && grid[rc][rr] == '1'){
                                q.push({rc,rr});
                                grid[rc][rr] = '0';
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};