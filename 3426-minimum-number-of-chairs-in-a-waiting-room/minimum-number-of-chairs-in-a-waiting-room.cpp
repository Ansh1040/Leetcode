class Solution {
public:
    int minimumChairs(string s) {
        int e=0;
        int l=0;
        int ans=0;
        for(int i=0 ; i<s.length() ; i++){
            if(s[i]=='E') e++;
            else e--;
            ans = max(ans , e);
        }
        return ans;
    }
};