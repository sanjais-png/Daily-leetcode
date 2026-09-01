class Solution {
public:

    class ChessNode{
    public:
        int row;
        int col;
        int next;
        ChessNode(int r , int c , int n){
            row = r;
            col = c;
            next = n;
        }
    };
    vector<int> dx = {2,1,2,1,-2,-1,-2,-1};
    vector<int> dy = {1,2,-1,-2,1,2,-1,-2};
    bool isValid(int currentR , int currentC , int nextR , int nextC){
        for(int i = 0 ; i < 8 ; i++){
            int validR = currentR + dx[i];
            int validC = currentC + dy[i];
            if(validR == nextR && validC == nextC){
                return true;
            }
        }
        return false;
    }


    bool checkValidGrid(vector<vector<int>>& grid) {
        if(grid[0][0]!=0){return false;}
        auto compare = [](const ChessNode& a, const ChessNode& b) {
            return a.next > b.next;
        };
        priority_queue<ChessNode , vector<ChessNode> ,decltype(compare)> pq(compare);
        for(int i = 0 ; i < grid.size() ; i++){
            for(int j = 0 ; j < grid[0].size() ; j++){
                ChessNode a(i , j , grid[i][j]);
                pq.push(a);
            }
        }
        pq.pop();
        int currentRow = 0 , currentCol = 0;
        while(!pq.empty()){
            ChessNode a = pq.top();
            int nextRow = a.row;
            int nextCol = a.col;
            pq.pop();
            if(!isValid(currentRow , currentCol , nextRow , nextCol)){
                return false;
            }
            currentRow = nextRow;
            currentCol = nextCol;
        }
        return true;;
    }
};