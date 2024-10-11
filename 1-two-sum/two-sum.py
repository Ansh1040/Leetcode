# vector<int> twoSum(vector<int>& nums, int target) {
#         int n = nums.size();
#         for (int i = 0; i < n - 1; i++) {
#             for (int j = i + 1; j < n; j++) {
#                 if (nums[i] + nums[j] == target) {
#                     return {i, j};
#                 }
#             }
#         }
#         return {};
        
#     }


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        n = len(nums)
        for i in range(n-1):
            for j in range(i+1, n ):
                 if (nums[i] + nums[j] == target): return[i,j]
        return[]