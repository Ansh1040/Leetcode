class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        // int ans = 0;
        // for (auto& x : nums) {
        //     ans = ans ^ x;
        // }
        // ans = ans ^ k;
        // int res = 0;
        // while (ans > 0) {
        //     if (ans & 1)
        //         res++;
        //     ans = ans >> 1;
        // }
        // return res;

        
        int xors =k;
        for(auto it :nums){
            xors ^=it;
        }
//         xors with k and count no of setbits as operations
        // xors =xors^k;
        return __builtin_popcount(xors);
    }
};