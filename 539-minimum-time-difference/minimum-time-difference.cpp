class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        // sort(timePoints.begin(),timePoints.end());
        // for(auto i: timePoints){
        //     int a = stoi(i[0])*10+stoi(i[1]);
        //     int b = stoi(i[0])*10+stoi(i[1]);
        //     int c = stoi(i[0])*10+stoi(i[1]);
        //     int d = stoi(i[0])*10+stoi(i[1]);
        //     if(a==0||c==0)a=24;c=24;
        //     if(b==0||d==0)b=60;d=60;
            
        // }

         vector<int> minutes(timePoints.size());
        
        // Convert times to minutes
        for (int i = 0; i < timePoints.size(); ++i) {
            int h = stoi(timePoints[i].substr(0, 2));
            int m = stoi(timePoints[i].substr(3));
            minutes[i] = h * 60 + m;
        }

        // Sort times in ascending order
        sort(minutes.begin(), minutes.end());

        // Find minimum difference across adjacent elements
        int minDiff = INT_MAX;
        for (int i = 0; i < minutes.size() - 1; ++i) {
            minDiff = min(minDiff, minutes[i + 1] - minutes[i]);
        }

        // Consider the circular difference between last and first element
        minDiff = min(minDiff, 24 * 60 - minutes.back() + minutes.front());

        return minDiff;



        

    }
};