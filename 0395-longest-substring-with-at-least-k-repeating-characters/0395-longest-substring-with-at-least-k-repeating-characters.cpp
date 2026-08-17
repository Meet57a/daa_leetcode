class Solution {
public:
    int solve(string& s, int left, int right, int k) {
        if (right - left + 1 < k) {
            return 0;
        }

        // Count frequency
        vector<int> freq(26, 0);

        for (int i = left; i <= right; i++) {
            freq[s[i] - 'a']++;
        }

        // Find a character whose frequency is less than k
        for (int i = left; i <= right; i++) {
            if (freq[s[i] - 'a'] < k) {

                // Split around this invalid character
                int next = i + 1;

                while (next <= right && freq[s[next] - 'a'] < k) {
                    next++;
                }

                return max(
                    solve(s, left, i - 1, k),
                    solve(s, next, right, k)
                );
            }
        }

        // Every character appears at least k times
        return right - left + 1;
    }

    int longestSubstring(string s, int k) {
        return solve(s, 0, s.size() - 1, k);
    }
};