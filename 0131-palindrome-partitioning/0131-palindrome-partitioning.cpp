class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> sub;
        backtrack(0, s, sub, res);
        return res;
    }

private:
    void backtrack(int i, string& s, vector<string>& sub,
                   vector<vector<string>>& res) {
        if (i == s.size()) {
            res.push_back(sub);
            return;
        }
        for (int j = i; j < s.size(); j++) {
            if (Palindrome(s, i, j)) {
                sub.push_back(s.substr(i, j - i + 1));
                backtrack(j + 1, s, sub, res);
                sub.pop_back();
            }
        }
    }

    bool Palindrome(const string& s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--])
                return false;
        }
        return true;
    }
};