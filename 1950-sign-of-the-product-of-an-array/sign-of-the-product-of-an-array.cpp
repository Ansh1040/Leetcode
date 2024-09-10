class Solution {
public:
    int arraySign(vector<int>& nums) {
        int multi=1;
        for(int i=0 ; i< nums.size() ; i++){
             if(nums[i]<0)
             multi*=-1;
            else if(nums[i]>0)
             multi*=1;
            else
              multi=0;
        }
        if(multi >= 1) return 1;
        if(multi <= -1) return -1;
        return 0;
    }
};