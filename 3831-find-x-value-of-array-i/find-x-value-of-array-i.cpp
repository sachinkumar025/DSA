class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int val = num % k;

            vector<long long> next(k, 0);

            // Subarray containing only current element
            next[val] = 1;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * val) % k;
                next[newR] += dp[r];
            }

            // Add current subarrays to answer
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};