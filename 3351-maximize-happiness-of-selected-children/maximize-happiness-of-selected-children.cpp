class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long ans = 0;
        sort(happiness.rbegin() , happiness.rend());
        for (int turn = 0 ; turn < k; ++turn ) {
            long long current = max(happiness[turn] - turn, 0);
            ans+= current;
        }
        return ans;
    }
};