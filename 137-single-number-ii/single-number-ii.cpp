class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // sort(nums.begin(), nums.end()); 
        // int ans =0 ;
        // for (int i = 0; i < nums.size(); i += 3) {
        //     if (i == nums.size() - 1 || nums[i] != nums[i + 1]) {
        //         ans = nums[i];
        //         break;
        //     }
        // }
        // return ans;

        int ans =0 ;
        for(int bit = 0 ; bit<=31 ; bit++){
            int count1=0;
            int temp = (1<<bit);                         //  1 left shift bit times
            for(int &num : nums ){           
                if( ( num & temp ) != 0) count1++;       // to check if it is 1 or not 
            }
            if(count1 % 3 ==1) ans = ( ans | temp );     // to check if it is repeting 3 times 
        }
        return ans;
    }
};