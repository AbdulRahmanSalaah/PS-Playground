class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans;
        int l = 0;
        int r = max(word1.size(), word2.size());
        while (l < r) {
            if (l < word1.size()) {
                ans.push_back(word1[l]);
            }
            if (l < word2.size()) {
                ans.push_back(word2[l]);
            }
            l++;
        }
        return ans;
    }
};