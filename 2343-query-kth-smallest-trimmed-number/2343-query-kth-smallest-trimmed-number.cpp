class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int L = nums[0].size();
        vector<int> answer;
        answer.reserve(queries.size());
        
        for (auto& q : queries) {
            int k = q[0], trim = q[1];
            
            // indices 0..n-1, sorted by trimmed substring (last `trim` chars), 
            // ties broken by original index (stable sort handles this automatically
            // since we compare only the trimmed value, keeping original relative order on ties)
            vector<int> idx(n);
            for (int i = 0; i < n; i++) idx[i] = i;
            
            int start = L - trim;
            
            stable_sort(idx.begin(), idx.end(), [&](int a, int b) {
                // compare substrings from `start` to end (both have length `trim`, so plain
                // lexicographic comparison correctly reflects numeric comparison, like digit strings
                // of equal length)
                for (int j = start; j < L; j++) {
                    if (nums[a][j] != nums[b][j]) {
                        return nums[a][j] < nums[b][j];
                    }
                }
                return false; // equal trimmed values -> stable_sort preserves original order
            });
            
            answer.push_back(idx[k - 1]);
        }
        
        return answer;
    }
};