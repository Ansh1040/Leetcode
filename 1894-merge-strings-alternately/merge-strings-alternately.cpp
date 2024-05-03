class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string output = "";
        int mini=min(word1.size(), word2.size());
            for(int i=0 ; i<mini ; i++){
                output+=word1[i];
                output+=word2[i];
            }
        for(int i=mini ; i<word1.size() ; i++){
            output+=word1[i];
        }
        for(int i=mini ; i<word2.size() ; i++){
            output+=word2[i];
        }
        return output;
    }
};