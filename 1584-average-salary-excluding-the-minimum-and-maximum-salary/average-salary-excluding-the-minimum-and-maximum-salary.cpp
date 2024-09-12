class Solution {
public:
    double average(vector<int>& salary) {
        double ans =0;
        int mn = INT_MAX , mx=INT_MIN;
        for(int i =0;i<salary.size();i++){
            mn = min(mn , salary[i]);
            mx = max(mx,salary[i]);
            ans +=salary[i];
        }
        ans = ans - mn - mx;
        ans = ans/(salary.size()-2);
        return ans;
    }
};