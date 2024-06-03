class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0;
        int maxi=0;
        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i]==1)ans++;
            else{
                maxi = max( maxi , ans );
                ans=0;
            }
        }
        return max( maxi , ans );
    }
};