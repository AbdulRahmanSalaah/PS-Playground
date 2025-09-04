class Solution {
public:
    vector<string> res;
    vector<string> digitToChar = {"",    "",    "abc",  "def", "ghi",
                                  "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {

        if (digits.empty())
            return res;

        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int i, string str, string& digits) {
        if (str.size() == digits.size()) {
            res.push_back(str);
            return;
        }
        string chars = digitToChar[digits[i] - '0'];
        for (char c : chars) {
            str.push_back(c);
            backtrack(i + 1, str, digits);
            str.pop_back();
        }
    }
};