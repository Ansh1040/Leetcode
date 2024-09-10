class Solution {
public:
    char findTheDifference(string s, string t) {
        int asciSumS = 0;
        int asciSumT = 0;
        for(auto i : s){
            asciSumS+=int(i);
        }
        for(auto i : t){
            asciSumT+=int(i);
        }
        int ans = asciSumT-asciSumS;
        return char(ans);
    }
};