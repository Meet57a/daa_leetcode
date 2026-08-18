class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int totalSum = 0;
        int curMax = 0, maxSum = INT_MIN;
        int curMin = 0, minSum = INT_MAX;
        
        for (int num : nums) {
            totalSum += num;
            
            // Kadane's algorithm for max subarray sum
            curMax = max(curMax, 0) + num;
            maxSum = max(maxSum, curMax);
            
            // Kadane's algorithm for min subarray sum
            curMin = min(curMin, 0) + num;
            minSum = min(minSum, curMin);
        }
        
        // If all numbers are negative, maxSum will be the best (least negative) answer,
        // and totalSum - minSum would incorrectly be 0 (empty subarray), so return maxSum directly.
        if (maxSum < 0) {
            return maxSum;
        }
        
        return max(maxSum, totalSum - minSum);
    }
};