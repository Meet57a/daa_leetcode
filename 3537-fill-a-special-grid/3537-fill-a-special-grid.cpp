class Solution {
public:
    vector<vector<int>> specialGrid(int n) {
        int size = 1 << n; // 2^n
        vector<vector<int>> grid(size, vector<int>(size, 0));
        fill(grid, 0, 0, size, 0);
        return grid;
    }
    
private:
    // Fills the size x size subgrid whose top-left corner is at (row, col) with
    // consecutive integers starting from startVal, ordered so that:
    // top-right < bottom-right < bottom-left < top-left (each quadrant recursively).
    // Returns the next available value after filling.
    int fill(vector<vector<int>>& grid, int row, int col, int size, int startVal) {
        if (size == 1) {
            grid[row][col] = startVal;
            return startVal + 1;
        }
        
        int half = size / 2;
        
        // Order: top-right, bottom-right, bottom-left, top-left (ascending value order)
        int val = startVal;
        val = fill(grid, row, col + half, half, val);        // top-right
        val = fill(grid, row + half, col + half, half, val); // bottom-right
        val = fill(grid, row + half, col, half, val);        // bottom-left
        val = fill(grid, row, col, half, val);                // top-left
        
        return val;
    }
};