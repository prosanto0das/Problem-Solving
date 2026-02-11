//https://leetcode.com/problems/longest-substring-without-repeating-characters

// No prerequisite
// Approach: sliding window without using map or set

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // Use vector array instead of map/set
        vector<int>last_ocr(256, -1);
        int mx = 0;
        int last_repeat = -1;
        int n = s.size();
        for(int i = 0; i < n; i++)
        {
            int z = s[i];
            last_repeat = max(last_repeat, last_ocr[z]);
            mx = max(mx, i - last_repeat);
            last_ocr[z] = i;
        }
        return mx;
    }
};