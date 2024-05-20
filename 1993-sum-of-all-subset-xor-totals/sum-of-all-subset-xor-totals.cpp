class Solution {
public:

    int helper(vector<int>& nums, int level, int currentXOR) {

        if (level == nums.size()) return currentXOR;                      // base condition
        
        int include = helper(nums, level + 1, currentXOR ^ nums[level]);  // creating include 
        
        int exclude = helper(nums, level + 1, currentXOR);                // creating exclude
        
        return include + exclude;

    }    

    int subsetXORSum(vector<int>& nums) {
        return helper(nums , 0 , 0);
    }
};