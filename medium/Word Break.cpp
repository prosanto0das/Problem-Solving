
//https://leetcode.com/problems/word-break/description
// dp 

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.size();
        map<string, int>mp;
        for(auto it: wordDict)mp[it] = 1;
        vector<int>is_poss(n, 0);
        for(int i = 0; i < n; i++)
        {
            string tmp = "";
            for(int j = i; j >= 0; j--)
            {
                tmp = s[j] + tmp;
                if(mp[tmp])
                {
                    if(j == 0 || is_poss[j - 1] == 1)is_poss[i] = 1;
                }
            }
        }
        return is_poss[n - 1];

        
    }
};