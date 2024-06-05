class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
    vector<int> minFreq(26, 0); 

    for (char ch : words[0]) {
        minFreq[ch - 'a']++;
    }
    for (int i = 1; i < words.size(); i++) {
        vector<int> freq(26, 0);
        for (char ch : words[i]) {
            freq[ch - 'a']++;
        }
        for (int j = 0; j < 26; j++) {
            minFreq[j] = min(minFreq[j], freq[j]);
        }
    }
    vector<string> result;
    for (int i = 0; i < 26; i++) {
        while (minFreq[i]--) {
            result.push_back(string(1, 'a' + i));
        }
    }
    return result;
    }
};