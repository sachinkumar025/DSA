class Solution {
public:
    int jump(vector<int>& nums) 
    {
        int count = 0, end = 0,maxjump = 0;
        for(int i = 0;i<nums.size() - 1; i++){
            maxjump = max(maxjump, i + nums[i]);
            if(i == end) {
                count++;
                end = maxjump;

            }
        }
        return count;
    }
};