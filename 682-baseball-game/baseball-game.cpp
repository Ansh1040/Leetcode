class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> a;
        
        for (const string& op : operations) {
            if (op == "+") {
                a.push_back(a[a.size() - 1] + a[a.size() - 2]);
            } 
            else if (op == "D") 
            {
                a.push_back(2 * a.back());
            } 
            else if (op == "C") {
                a.pop_back();
            } 
            else {
                a.push_back(stoi(op));
            }
        } 
        return accumulate(a.begin(), a.end(), 0);
    }
};