class Solution {
    vector<int> memo;

public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memo.assign(s.size() + 1, -1);
        return helper(0, s, wordDict);
    }

    bool helper(int i, string& s, vector<string>& wordDict) {
        if (i == s.size()) return true;
        if (memo[i] != -1) return memo[i];

        for (auto& w : wordDict) {
            int len = w.size();
            if (i + len <= s.size() && s.substr(i, len) == w) {
                if (helper(i + len, s, wordDict))
                    return memo[i] = true;
            }
        }

        return memo[i] = false;
    }
};
