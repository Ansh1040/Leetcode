class Solution {
public:
    double average(vector<int>& salary) {

        //    O(n)

        // double ans =0;
        // int mn = INT_MAX , mx=INT_MIN;
        // for(int i =0;i<salary.size();i++){
        //     mn = min(mn , salary[i]);
        //     mx = max(mx,salary[i]);
        //     ans +=salary[i];
        // }
        // ans = ans - mn - mx;
        // ans = ans/(salary.size()-2);
        // return ans;



        //    O(n(log(n)))

        sort(salary.begin(), salary.end());
        double ans =0;
        int n = salary.size();
        for(int i=1; i<n-1;i++){
            ans +=salary[i];
        }
        ans = ans/(n-2);
        return ans;
    }
};