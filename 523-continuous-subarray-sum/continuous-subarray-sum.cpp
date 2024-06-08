class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        // int n = nums.size();
        
        // // Step 1: Iterate Through Starting Points
        // for (int start = 0; start < n - 1; start++) {
        //     // Step 2: Expand the Subarray
        //     for (int end = start + 1; end < n; end++) {
        //         // Step 3: Calculate the Sum
        //         int subarraySum = 0;
        //         for (int i = start; i <= end; i++) {
        //             subarraySum += nums[i];
        //         }
                
        //         // Step 4: Check if the Sum is a Multiple of k
        //         if (subarraySum == 0 && k == 0) { // Handling special case where k is 0
        //             return true;
        //         }
        //         if (k != 0 && subarraySum % k == 0) {
        //             return true;
        //         }
        //     }
        // }
        
        // // Step 5: Return the Result
        // return false;


         int n = nums.size();
        unordered_map<int, int> remainderMap;
        int cumulativeSum = 0;
        
        // Step 1: Initialize Remainder Map
        remainderMap[0] = -1;
        
        // Step 2: Iterate Through the List
        for (int i = 0; i < n; i++) {
            // Step 3: Calculate Cumulative Sum
            cumulativeSum += nums[i];
            
            // Step 4: Calculate Remainder
            int remainder = k == 0 ? cumulativeSum : cumulativeSum % k;
            
            // Step 5: Update Remainder Map
            if (remainderMap.count(remainder)) {
                // Check if segment length is at least two
                if (i - remainderMap[remainder] > 1) {
                    return true;
                }
            } else {
                remainderMap[remainder] = i;
            }
        }
        
        // Step 6: Return the Result
        return false;
    }
};