class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int fresh = 0 , n = grid.size() , m = grid[0].size();
        queue<vector<int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j] == 2){
                    q.push(vector<int>{i,j});
                }
                if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }
        if(fresh == 0){return 0;}
        vector<vector<int>>dir{ {0,-1} , {0,1} , {-1,0} , {1,0} };
        int mins = 0;
        
        while(!q.empty()){
            int size = q.size();
            if(fresh > 0){
                mins++;
            }
            for(int i = 0 ; i < size ; i++){
                vector<int>v = q.front();
                q.pop();
                for(int j = 0 ; j < 4 ; j++){
                    int rr = v[0] + dir[j][0];
                    int rc = v[1] + dir[j][1];
                    if(rr >= 0 && rc >=0 && rr < n && rc < m && grid[rr][rc] == 1){
                        grid[rr][rc] = 2;
                        q.push(vector<int>{rr,rc});
                        fresh--;
                    }
                }
            }
            
        }
        if(fresh > 0){
            return -1;
        }
        return mins;
    }
};