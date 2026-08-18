class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long MOD = 1000000007;
        int n = nums.size();
        
        vector<long> arr(nums.begin(), nums.end());
        
        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            for (int idx = l; idx <= r; idx += k) {
                arr[idx] = (arr[idx] * v) % MOD;
            }
        }
        
        int result = 0;
        for (long x : arr) {
            result ^= (int)x;
        }
        
        return result;
    }
};