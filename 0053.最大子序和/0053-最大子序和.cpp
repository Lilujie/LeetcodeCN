class Solution {
public:
    int maxSubArray(vector<int>& nums) {

        int len = nums.size();
        if (len == 0) return 0;

        int result = nums[0];        
        int dp[len];
        dp[0] = nums[0];
        for (int i = 1; i < len; i++) {
            dp[i] = max(dp[i-1] + nums[i], nums[i]);
            if (result < dp[i]) result = dp[i];
        }
        return result;
    }
};