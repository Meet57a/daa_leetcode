/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* construct(vector<vector<int>>& grid) {
        int n = grid.size();
        return build(grid, 0, 0, n);
    }
    
private:
    Node* build(vector<vector<int>>& grid, int r, int c, int size) {
        // Check if all values in this subgrid are the same
        int first = grid[r][c];
        bool same = true;
        for (int i = r; i < r + size && same; i++) {
            for (int j = c; j < c + size; j++) {
                if (grid[i][j] != first) {
                    same = false;
                    break;
                }
            }
        }
        
        if (same) {
            return new Node(first == 1, true);
        }
        
        int half = size / 2;
        Node* topLeft = build(grid, r, c, half);
        Node* topRight = build(grid, r, c + half, half);
        Node* bottomLeft = build(grid, r + half, c, half);
        Node* bottomRight = build(grid, r + half, c + half, half);
        
        return new Node(true, false, topLeft, topRight, bottomLeft, bottomRight);
    }
};