class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) { 
        int ans =0;       
        int a=0,b=0;

        for(int i=0 ; i<nums.size() ; i++){
            ans ^=nums[i];
        }

        int SetBit = ans & -(unsigned int)ans;            //  explanation in notes

        for (int num : nums) {
            if (num & SetBit) {
                a ^= num;
            } else {
                b ^= num;
            }
        }
        return {a,b};
    }
};