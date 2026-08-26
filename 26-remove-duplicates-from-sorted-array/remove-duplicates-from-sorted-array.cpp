class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = i;

        while(j < n) {
            if(nums[i] != nums[j]) {
                i++;
                nums[i] = nums[j];
            }

            j++;
        }
        return i+1;
    }
};