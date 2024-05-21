class Solution {
public:

    vector<vector<int>>helper(vector<int>&nums , int start, vector<int>& path, vector<vector<int>>&ans){
        ans.push_back(path);
        for(int i=start ; i<nums.size() ; i++){
            path.push_back(nums[i]);
            helper(nums, i + 1, path, ans);
            path.pop_back();
        }
        return ans;
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>>ans;
        // vector<int> path;
        // return helper(nums,0, path, ans);          // backtracking


        vector<vector<int>> result = {{}};           
        for (int num : nums) {                        // iterative
            int size = result.size();
            for (int i = 0; i < size; i++) {
                vector<int> subset = result[i];
                subset.push_back(num);
                result.push_back(subset);
            }
        }
        return result;
    }
};