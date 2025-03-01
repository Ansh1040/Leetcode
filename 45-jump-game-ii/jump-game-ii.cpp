class Solution {
public:
    int jump(vector<int>& nums) {
        int  x=0, start = 0;
        int ans=0;


       while(start < nums.size()-1){
            int reach = 0;
            for(int i=x ; i<= start ; i++){
                reach = max(reach , i + nums[i]);
            }
            x = start+1;
            start = reach ;
            ans++;
        }
        return ans;        
    }
};