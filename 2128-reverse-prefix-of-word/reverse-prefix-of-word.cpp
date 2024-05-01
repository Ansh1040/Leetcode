class Solution {
public:
    string reversePrefix(string word, char ch) {
        int c=0;
        for(int i=0;i<word.length();i++){
            if(word[i]==ch){
                c=i;
                break;
            }
        }
        string ans=word.substr(0,c+1);
        reverse(ans.begin(),ans.end());
        ans=ans+word.substr(c+1,word.length());
        return ans;
    }
};