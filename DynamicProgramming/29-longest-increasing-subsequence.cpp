#include <vector>
#include <algorithm>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        if (nums.empty()) return 0;
        
        int n = nums.size();
        std::vector<int> dp(n, 1); // Every element is an LIS of length 1 by itself
        int maxLen = 1;
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = std::max(dp[i], dp[j] + 1);
                }
            }
            maxLen = std::max(maxLen, dp[i]);
        }
        
        return maxLen;
    }
};
