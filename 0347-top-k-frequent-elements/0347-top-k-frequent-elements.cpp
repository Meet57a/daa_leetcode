class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        // Count frequency
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // bucket[i] contains numbers that appear i times
        vector<vector<int>> bucket(nums.size() + 1);

        for (auto& [num, count] : freq) {
            bucket[count].push_back(num);
        }

        vector<int> result;

        // Start from highest frequency
        for (int i = nums.size(); i >= 1 && result.size() < k; i--) {
            
            for (int num : bucket[i]) {
                result.push_back(num);

                if (result.size() == k) {
                    break;
                }
            }
        }

        return result;
    }
};