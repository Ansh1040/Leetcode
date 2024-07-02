class Solution {
public:
    vector<int> intersection(vector<vector<int>>& nums) {
        // int n=nums.size();
        // vector<int> result;
        // unordered_map<int,int> umap;
        // for(int i=0;i<nums.size();i++)
        // {
        //     for(int j=0;j<nums[i].size();j++)
        //     {
        //         if(umap[nums[i][j]]<i+1)
        //         {
        //             umap[nums[i][j]]++;
        //         }
        //     }
        // }
        
        // for(auto i=umap.begin();i!=umap.end();i++)
        // {
        //     if(i->second==n)
        //     {
        //         result.push_back(i->first);
        //     }
        // }
        // sort(result.begin(),result.end());
        // return result;



         vector<int> hsh(1005,0),ans;
        for(auto&_nums:nums)
            for(int&x:_nums)
                hsh[x]++;
        for(int i=1; i<hsh.size(); i++)
            if(hsh[i]==nums.size()) ans.push_back(i);
        return ans;

    }
};