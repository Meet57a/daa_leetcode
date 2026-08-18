class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m = matrix.size(), n = matrix[0].size();
        
        // prefixXor[i][j] = XOR of all matrix[x][y] for x in [0,i), y in [0,j)
        vector<vector<int>> prefixXor(m + 1, vector<int>(n + 1, 0));
        
        vector<int> values;
        values.reserve(m * n);
        
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // 2D prefix XOR formula (inclusion-exclusion, XOR is its own inverse)
                prefixXor[i][j] = matrix[i-1][j-1] 
                                 ^ prefixXor[i-1][j] 
                                 ^ prefixXor[i][j-1] 
                                 ^ prefixXor[i-1][j-1];
                values.push_back(prefixXor[i][j]);
            }
        }
        
        // Find kth largest via nth_element (average O(n))
        nth_element(values.begin(), values.begin() + k - 1, values.end(), greater<int>());
        
        return values[k - 1];
    }
};