class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty())
            return {};

        vector<string> digitToChar = {"",    "",    "abc",  "def", "ghi",
                                      "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;

        string curr = "";
        backtrack(0, digits, digitToChar, curr, res);
        return res;
    }

    void backtrack(int i, string& digits, vector<string>& digitToChar,
                   string& curr, vector<string>& res) {
        if (curr.size() == digits.size()) {
            res.push_back(curr);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            curr.push_back(c);
            backtrack(i + 1, digits, digitToChar, curr, res);
            curr.pop_back();
        }
    }
};