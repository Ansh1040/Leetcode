class Solution {
public:
    unordered_map<char, vector<int>> index;
    int find(int i, string &key, string &ring, int j, vector<vector<int>> &memo) {

        //If we don't have any key, no steps needed
        if(i>=key.size()) return 0;

        //Already calculated for this state
        if(memo[i][j]!=-1) return memo[i][j];

        //Current key, where we need to reach(i.e rotate ring)
        char currChar = key[i];
        int ans = INT_MAX;
    
        //Since, there will be many frequency of key[i] in ring, so iterating on them and making roating ring for each
        for(int ind: index[currChar]) {

            //Rotating ring towards left and bring ring[ind] at 12:00
            int lftRotateStep = abs(ind-j);

            //Rotating ring towards right and bring ring[ind] at 12:00
            int rgtRotateStep = ring.size()-abs(ind-j);

            // Taking minimum steps, and calling recursive method for next key(i+1) and with next ind, which is now at 12:00
            ans = min(ans, min(lftRotateStep,rgtRotateStep)+find(i+1,key,ring,ind,memo));
        }

        // adding 1 because 1 step will be required to spell this character
        return memo[i][j] = 1+ans;
    }
    int findRotateSteps(string ring, string key) {

        int m = key.size(), n = ring.size();
        vector<vector<int>> memo(m+1, vector<int>(n+1,-1));

        //Storing index of every character
        for(int i=0; i<ring.size(); i++) {
            index[ring[i]].push_back(i);
        }
        //starting from key[0] and since, ring[0] at 12:00, so passing 0 here last param
        return find(0,key,ring,0,memo);
    }
};