class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int maxl = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd
            expand(s, i, i, res, maxl);
            // even
            expand(s, i, i + 1, res, maxl);
        }
        return res;
    }

    void expand(string& s, int l, int r, string& res, int& maxl) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            if (r - l + 1 > maxl) {
                res = s.substr(l, r - l + 1);
                maxl = r - l + 1;
            }
            l--;
            r++;
        }
    }
};