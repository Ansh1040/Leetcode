class Solution {
public:

    int solve(vector<int>&nums , int k , int index , vector<int>&temp){
        int n = nums.size();
        if(index == n) return 1;

        int pick =0 ;
        int notPick = 0;

        if(find(temp.begin() , temp.end() , nums[index]-k)==temp.end() && find(temp.begin() , temp.end() , nums[index]+k)==temp.end()){
            temp.push_back(nums[index]);
            pick=solve(nums , k , index+1 , temp);
            temp.pop_back();
        }
        notPick = solve(nums , k , index+1 , temp);
        return pick+notPick;

    }

    int beautifulSubsets(vector<int>& nums, int k) {

        // int count = 0 ;
        // sort(nums.begin() , nums.end());
        // for(int i=0 ; i<nums.size() ; i++){
        //     for(int j=i ; j<nums.size() ; j++){
        //         if(nums[i]-nums[j] != k and nums[j]-nums[i] != k ) count++;
        //     }
        // }
        // return count;

        vector<int>temp;
        return solve(nums , k , 0 , temp)-1;

    }
};