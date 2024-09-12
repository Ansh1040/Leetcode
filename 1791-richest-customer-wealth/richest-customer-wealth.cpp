class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        // int maxi=0;
        
        // for(int i=0 ; i < accounts.size() ; i++){
        //     int ans=0;
        //     for(int j=0 ; j<accounts[i].size(); j++){
        //         ans += accounts[i][j];
        //     }
        //     maxi = max(maxi , ans);
        // }
        // return maxi;

        int maxsum = 0;
        for (auto acc:accounts){
            int sum=0;
            for(int x:acc){
                sum+=x;
                if(sum>maxsum) maxsum=sum;
            }
        }
        return maxsum;
    
    }
};