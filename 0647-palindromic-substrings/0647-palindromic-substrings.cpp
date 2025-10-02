class Solution {
public:
    int countSubstrings(string s) {
        int res = 0;
        for (int i = 0; i < s.size(); i++) {
            // odd
            expand(s, i, i, res);
            // even
            expand(s, i, i + 1, res);
        }
        return res;
    }

    void expand(string& s, int l, int r, int& res) {
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            res++;
            l--;
            r++;
        }
    }
};