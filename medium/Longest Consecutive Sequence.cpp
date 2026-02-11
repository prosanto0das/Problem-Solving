// https://leetcode.com/problems/longest-consecutive-sequence/description



// you can do it in this way beacuse
// avg case of unorderset is o(n)
// so it matches the problem description of O(n)
// but it's not fastest 
// second method is fastest

// method--1


class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       

        unordered_set<int>st;
        for(auto it: nums) st.insert(it);
        int mx = 0;
        int prev = 1e9+5;
        for(auto it: st)
        {
            int cnt = 1;
            int fnd = it + 1;
           if(st.find(it - 1) == st.end())
           {
                while(st.find(fnd) != st.end())
                {
                    cnt++;
                    fnd++;
                }
           }
           mx = max(mx, cnt);
        }
        return mx;


    }
};


// method-2

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        sort(nums.begin(),nums.end());
       int mx = 1;
       int n = nums.size();
       int curr = nums[0];
       int cnt = 1;
       for(int i = 1; i < n; i++)
       {
            if(nums[i] == curr) continue;
            else if(nums[i] == curr + 1)
            {
                curr++;
                cnt++;
            }
            else
            {
                cnt = 1;
                curr = nums[i];
            }
            mx = max(mx, cnt);
       }
       mx = max(mx, cnt);
       return mx;
        
    }
};