#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> answer;

    void rec(int open, int close, string s)
    {

        if (open == 0 && close == 0)
        {
            answer.push_back(s);
            return;
        }
        if (open != 0)
        {
            rec(open - 1, close, s + "(");
        }
        if (close > open)
        {
            rec(open, close - 1, s + ")");
        }
    }

    vector<string> generateParenthesis(int n)
    {

        rec(n, n, "");
        return answer;
    }
};