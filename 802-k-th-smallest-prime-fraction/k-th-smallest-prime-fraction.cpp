class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        vector<vector<double>> pairs;
        int n = arr.size();
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                pairs.push_back({arr[i]*1.0/arr[j]*1.0, arr[i]*1.0 , arr[j]*1.0});
            }
        }
        sort(pairs.begin(), pairs.end());
        int first = pairs[k-1][1];
        int sec = pairs[k-1][2];
        return {first, sec};
    }
};