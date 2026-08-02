class Solution {
public:
    void dfs(vector<vector<char>>& grid, int row, int col) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        
        if (row < 0 || row >= numRows || col < 0 || col >= numCols || grid[row][col] == '0') {
            return;
        }
        
        grid[row][col] = '0';
        
        dfs(grid, row - 1, col);
        dfs(grid, row + 1, col);
        dfs(grid, row, col - 1);
        dfs(grid, row, col + 1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int numRows = grid.size();
        int numCols = grid[0].size();
        int count = 0;
        
        for (int row = 0; row < numRows; row++) {
            for (int col = 0; col < numCols; col++) {
                if (grid[row][col] == '1') {
                    count++;
                    dfs(grid, row, col);
                }
            }
        }
        
        return count;
    }
};
