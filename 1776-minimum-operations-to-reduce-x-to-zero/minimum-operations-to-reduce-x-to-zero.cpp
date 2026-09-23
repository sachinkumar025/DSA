class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();

        int total = 0;
        for (int num : nums) {
            total += num;
        }

        int target = total - x;

        // x > total
        if (target < 0)
            return -1;

        // Need to remove all elements
        if (target == 0)
            return n;

        int left = 0;
        int sum = 0;
        int maxLen = -1;

        for (int right = 0; right < n; right++) {
            sum += nums[right];

            // Window sum target se bada ho gaya
            while (sum > target) {
                sum -= nums[left];
                left++;
            }

            // Target sum mil gaya
            if (sum == target) {
                maxLen = max(maxLen, right - left + 1);
            }
        }

        if (maxLen == -1)
            return -1;

        return n - maxLen;
    }
};