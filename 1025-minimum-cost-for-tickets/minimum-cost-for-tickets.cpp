// class Solution {
// private:

//     int solveTabulation(vector<int> days, vector<int> costs)
//     {
//         int n = days.size()-1;
//         vector<int> dp(n+2, -1);
//         dp[n+1]=0;

//         for(int i=n;i>=0;i--)
//         {
//             //1day
//             int cost1 = costs[0] + dp[i+1];

//             //7days
//             int endDayof7=days[i] + 7 - 1;
//             int currDayfor7 = i;
//             while(currDayfor7<days.size() && days[currDayfor7] <= endDayof7)
//                 currDayfor7++;
//             int cost7=costs[1] + dp[currDayfor7];

//             //30days
//             int endDayof30=days[i] + 30 - 1;
//             int currDayfor30=i;
//             while(currDayfor30<days.size() && days[currDayfor30] <= endDayof30)
//                 currDayfor30++;
//             int cost30=costs[2] + dp[currDayfor30];

//             dp[i] = min(cost1, min(cost7, cost30));
//         }

//         return dp[0];
//     }

// public:
//     int mincostTickets(vector<int>& days, vector<int>& costs) {
//         int ans = solveTabulation(days, costs);
//         return ans;
//     }
// };


class Solution {
public:
    int binary(int left, int right, int target, vector<int> &days)
    {
        if(target>days[days.size()-1] ) return days.size();

        while(left<right)
        {
            int mid=(left+right)/2;
            if(days[mid]==target) return mid;
            if(days[mid]<target) return binary(mid+1, right, target,days);
            else return binary(left,mid,target,days);
        }
        return left;
    }
    int solve(vector<int> &days, vector<int>& costs, vector<int> &dp, int index)
    {
        if (index>=days.size()) return 0;
        
        if(dp[index]!=-1) return dp[index];

        int seven_ind=0;
        if(days.size()-1>index+7)
        {
            seven_ind=binary(index,index+7,days[index]+7,days);
        }
        else seven_ind=binary(index,days.size()-1,days[index]+7,days);

        int thirty_ind=0;
        if(days.size()-1>index+30)
        {
            thirty_ind=binary(index,index+30,days[index]+30,days);
        }
        else thirty_ind=binary(index,days.size()-1,days[index]+30,days);

        int oneDay=costs[0]+solve(days,costs,dp,index+1);
        int sevenday=costs[1]+solve(days,costs,dp,seven_ind);
        int thirtyday=costs[2]+solve(days,costs,dp,thirty_ind);

        return dp[index]=min(min(oneDay,sevenday),thirtyday);
        
    }


    int mincostTickets(vector<int>& days, vector<int>& costs) {
    vector<int> dp(days.size()+1,-1);

    return solve(days,costs,dp,0);


    }
};