class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        // long long ans = 0;
        // sort(happiness.rbegin() , happiness.rend());
        // for (int turn = 0 ; turn < k; ++turn ) {
        //     long long current = max(happiness[turn] - turn, 0);
        //     ans+= current;
        // }
        // return ans;

         sort(happiness.begin(),happiness.end());
        int n = happiness.size();
         long long sum =0;
         int temp =0;
        for(int i=n-1;i>(n-1-k);i--){
            if(temp > happiness[i]){
                continue;
            }
            sum += (happiness[i]-temp);
            temp++;
        }

        return sum;
    }
};
