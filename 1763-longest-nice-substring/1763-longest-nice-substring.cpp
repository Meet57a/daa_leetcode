class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.empty()) return "";
        
        // Find the first character that breaks "niceness" (its other case isn't present)
        unordered_set<char> charSet(s.begin(), s.end());
        
        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            char other = islower(c) ? toupper(c) : tolower(c);
            
            if (!charSet.count(other)) {
                // c can't be part of any nice substring; split on it and recurse both halves
                string left = longestNiceSubstring(s.substr(0, i));
                string right = longestNiceSubstring(s.substr(i + 1));
                return left.size() >= right.size() ? left : right;
            }
        }
        
        // Entire string is nice
        return s;
    }
};